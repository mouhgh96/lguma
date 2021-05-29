#pragma once
#include <string_view>
#include <vector>
#include <memory>


class Stmt;
class AstNode {
  public:
    enum class Type {
      Chunck,
      FunctionDeclaration,
      Identifier,
      LetStmt,
      ReturnStmt,
      NumericLiteral,
    };
    Type type;
    // range
    AstNode(Type type):type{type}{}

};

class Stmt: public AstNode {
    public:
    Stmt(AstNode::Type type):AstNode(type){}
};
class Expr: public AstNode {
    public:
    Expr(AstNode::Type type):AstNode(type){}
};
class Chunck: public AstNode {
  public: 
    std::vector<std::unique_ptr<Stmt>> body;
    Chunck():AstNode(AstNode::Type::Chunck){}
    void push(std::unique_ptr<Stmt> stmt) {
      body.push_back(std::move(stmt));
    }
};

class Identifier: public Expr {
  public:
    std::string_view name;
    Identifier(std::string_view name):
      Expr(AstNode::Type::Identifier),
      name{name} {}

};
class AwaitStmt: public Stmt {
public:
  std::unique_ptr<Stmt> statement;
};

class ExportStmt: public Stmt {
public:
  std::unique_ptr<Stmt> statement;
};

class LetStmt: public Stmt {
  public: 
    std::unique_ptr<Identifier> variable;
    std::unique_ptr<Expr> init;
    LetStmt(std::unique_ptr<Identifier> variable, std::unique_ptr<Expr> init = nullptr):
      Stmt(AstNode::Type::LetStmt),
      variable{std::move(variable)},
      init{std::move(init)}
       {}

};
class ReturnStmt: public Stmt {
  public:
    std::unique_ptr<Stmt> argument;
    ReturnStmt(std::unique_ptr<Stmt> argument):
      Stmt(AstNode::Type::ReturnStmt),
      argument{std::move(argument)} {

      }
};
class NumericLiteral: public Expr {
  public:
    std::string_view raw;
    NumericLiteral(std::string_view raw):
      Expr(AstNode::Type::NumericLiteral),
      raw{raw} {

      }
};
class FunctionDeclaration: public Stmt {
  public:
    std::unique_ptr<Identifier> identifier;
    std::vector<std::unique_ptr<Identifier>> parameters;
    std::vector<Stmt> body;
    bool is_async;
    FunctionDeclaration(std::unique_ptr<Identifier> identifier,
                        std::vector<std::unique_ptr<Identifier>> parameters,
                        std::vector<Stmt> body,
                        bool is_async=false):
      Stmt(AstNode::Type::FunctionDeclaration),
      identifier{std::move(identifier)},
      parameters{std::move(parameters)},
      body{std::move(body)},
      is_async{is_async}
  {}
};
