#pragma once
#include "Ast.hpp"
#include "Heap.hpp"
#include "Value.hpp"
#include <cstdlib>
#include <fmt/core.h>
#include "FunctionObject.hpp"
#include "Env.hpp"
#include <charconv>
#define ENV_NODE_GUARD(env, fn, name) do {\
    if(!fn)  {\
      fmt::print("null node {}\n" ,name);\
      abort();\
      return nullptr;\
    }\
    if(!env) {\
      fmt::print("null env {} tnaket\n", name);\
       abort();\
      return nullptr;\
    }\
}while(false)
struct Visitor {

  Heap& heap;
  Visitor(Heap& heap):
  heap {heap}{

  }
  FunctionObject* visit(Env* env,  FunctionDeclaration * fn) {
    if(!fn)  {
      fmt::print("null function\n");
      return nullptr;
    }
    if(!env) {
      fmt::print("null env function declaration tnaket\n");
      return nullptr;

    }
    auto * ans = heap.make<FunctionObject>(env, fn->body);
    for(auto* param: fn->parameters) {
       ans->params.push_back(param->value);
    }
    env->insert(fn->identifier->value, (Value*)ans);
    return ans;
  }
  Value* visit(Env* env,  ReturnStmt * fn) {
    if(!fn)  {
      fmt::print("null function\n");
      return nullptr;
    }
    if(!env) {
      fmt::print("null env ReturnStmt tnaket\n");
      return nullptr;

    }
    if(!fn->argument)  {
      return heap.make<Value>();
    } 

    return visit(env, fn->argument);
  }
  Value* visit(Env* env, Expr* expr)  {
    ENV_NODE_GUARD(env, expr, "evaluating raw Expr"); 
    switch(expr->type) {
      case AstNode::Type::NumericLiteral:
        return visit(env, static_cast<NumericLiteral*>(expr));
        break;
      case AstNode::Type::FunctionCall:
        return visit(env, static_cast<FunctionCall*>(expr));
        break;
      default:
        fmt::print("unimplemented expr type visit Expr\n");
        abort();
    }
    return nullptr;
  }
  Value* visit(Env* env, NumericLiteral* numeric_literal)  {
    ENV_NODE_GUARD(env, numeric_literal, "evaluating numeric_literal"); 
    auto* ans = new Value;
    ans->type = Value::Type::Number;
    std::from_chars(numeric_literal->raw.data(), numeric_literal->raw.data() + numeric_literal->raw.size(), ans->obj.number);
    return ans;
  }
  Value* visit(Env* env, FunctionCall* fn)  {
    ENV_NODE_GUARD(env, fn, "evaluating function call");
    auto fn_object = (FunctionObject*)env->get(fn->name->value);
    if(!fn_object)
      {
        fmt::print("undefined function name {}\n",
                   fn->name->value);
        abort();
        return nullptr;
      }
    if(fn_object->params.size() != fn->args.size())
      {
        fmt::print("invalid number of arguments \n");
        abort();
        return nullptr;
      }
    Env scoped_env{env};
    for(auto i = 0; auto* expr: fn->args) {
        scoped_env.insert(fn_object->params[i],
                          visit(env, expr));
      }
    return visit(&scoped_env, (Chunck*)fn_object->fn_ast);
  }
  Value* visit(Env* env, Chunck* chunck)  {
    for(auto stmt: chunck->body) {
      
      switch(stmt->type) {
        case AstNode::Type::BlockStmt:
        case AstNode::Type::ExprStmt:
          visit(env, static_cast<ExprStmt*>(stmt)->expr);
          break;
        case AstNode::Type::FunctionDeclaration: 
          visit(env, static_cast<FunctionDeclaration*>(stmt));
          break;
        case AstNode::Type::ReturnStmt:
          visit(env, static_cast<ReturnStmt*>(stmt));
          break;
        default:
          {
            fmt::print("unimplemented Node Type \n");
          }
      }
    }
    return {};
  }
};
