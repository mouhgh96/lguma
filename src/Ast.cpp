#include <Ast.hpp>
#include <fmt/core.h>


AstNode::~AstNode() {

}
Stmt::~Stmt() {

}
Expr::~Expr() {

}
FunctionDeclaration::~FunctionDeclaration()  {
  delete identifier;
  delete body;
  identifier =nullptr; body = nullptr;
  for(size_t i = 0; i < parameters.size(); i++) {
    delete parameters[i];
    parameters[i] = nullptr;
  }
}

ExprStmt::~ExprStmt() {
  delete expr; 
  expr = nullptr;
}
FunctionCall::~FunctionCall() {
  delete name;
  name = nullptr;
  for(size_t i = 0; i < args.size(); i++) {
    delete args[i];
    args[i] = nullptr;
  }
}

NumericLiteral::~NumericLiteral()  {

}

ReturnStmt:: ~ReturnStmt()  {
      delete argument;
      argument = nullptr;
}


LetStmt::~LetStmt()  {
      delete variable;
      variable = nullptr;
      delete init;
      init = nullptr;
    };



ArrayExpr::~ArrayExpr()  {
      for(size_t i = 0; i < elements.size(); i++) {
        delete elements[i];
        elements[i] = nullptr;
      }
    };


ExportStmt::~ExportStmt()  {
      delete statement;
      statement = nullptr;
    };

AwaitStmt::~AwaitStmt()  {
      delete statement;
      statement = nullptr;
    };

Identifier::~Identifier() {

}


BlockStmt::~BlockStmt()  {
      for(size_t i = 0; i < body.size(); i++) {
        delete body[i];
        body[i] = nullptr;
      }
    };


Chunck::~Chunck()  {
  fmt::print("hna\n");
      for(size_t i = 0; i < body.size(); i++) {
        delete body[i];
        body[i] = nullptr;
      }
    };
