#include "Heap.hpp"
#include "Visitor.hpp"
#include <Ast.hpp>
#include <fmt/core.h>

int main() {
  Chunck *program = new Chunck;
  std::string fn_name = "printTips";
  Vector<Identifier *> parameters = {};
  std::string ret_value{"5"};
  BlockStmt *body = new BlockStmt;
  body->push(new ReturnStmt(new NumericLiteral(ret_value)));
  program->push(
      new FunctionDeclaration(new Identifier(fn_name), parameters, body));

  program->push(new ExprStmt(new FunctionCall(new Identifier(fn_name))));
  Env global_env;
  Heap heap;
  Visitor visitor{heap};
  visitor.visit(&global_env, program);
  delete program;
}
