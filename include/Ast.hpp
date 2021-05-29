#pragma once
#include <initializer_list>
#include <string_view>
#include <vector>

template<typename T>
using Vector = std::vector<T>;

#define NON_COPY_CONSTRUCTABLE(Class)\
  Class(const Class&) = delete;\
  Class& operator=(const Class&) = delete; 
class Stmt;
class AstNode {
  public:
    NON_COPY_CONSTRUCTABLE(AstNode);
    enum class Type {
      Chunck,
      FunctionDeclaration,
      Identifier,
      LetStmt,
      ReturnStmt,
      NumericLiteral,
      BlockStmt,
      ExprStmt,
      FunctionCall,
    };
    Type type;
    // range
    AstNode(Type type):type{type}{}

    virtual ~AstNode() = 0;
};

class Stmt: public AstNode {
    public:
    Stmt(AstNode::Type type):AstNode(type){}
     ~Stmt() override;
};
class Expr: public AstNode {
    public:
    Expr(AstNode::Type type):AstNode(type){}
    ~Expr() override;
};
class ExprStmt: public Stmt {
    public:
      Expr* expr;
    ExprStmt(Expr* expr):
      Stmt(AstNode::Type::ExprStmt),
      expr{expr}{}
     ~ExprStmt() override;
};
class Chunck: public AstNode {
  public: 
    Vector<Stmt*> body;
    Chunck():AstNode(AstNode::Type::Chunck){}
    void push(Stmt* stmt) {
      body.push_back(stmt);
    }
    ~Chunck() override ;
};

class BlockStmt: public Stmt {
  public: 
    Vector<Stmt*> body;
    BlockStmt():Stmt(AstNode::Type::BlockStmt){}
    void push(Stmt* stmt) {
      body.push_back(stmt);
    }
    ~BlockStmt() override ;
};
class Identifier: public Expr {
  public:
    std::string_view value;
    Identifier(std::string_view name):
      Expr(AstNode::Type::Identifier),
      value{name} {}
    ~Identifier() override;

};

class FunctionCall: public Expr {
  public:
    Vector<Expr*> args;
    Identifier* name;
    explicit FunctionCall(Identifier* name):
      Expr{AstNode::Type::FunctionCall},
      name{name}
    {}
    void push(Expr* arg) {
      args.push_back(arg);
    }
    void push(std::initializer_list<Expr*> args_list) {
       args.insert(args.end(), args_list.begin(), args_list.end());
    }
    void push(std::vector<Expr*> args_list) {
        args.insert(args.end(), args_list.begin(), args_list.end());
    }
    ~FunctionCall() override;
};
class AwaitStmt: public Stmt {
public:
  Stmt* statement;
    ~AwaitStmt() override;
};

class ExportStmt: public Stmt {
public:
  Stmt* statement;
  ~ExportStmt() override;
};
class ArrayExpr: public Expr {
public:
  Vector<AstNode*>  elements;

  void push(AstNode* node) {
    elements.push_back(node);
  }
    ~ArrayExpr() override ;
};

class LetStmt: public Stmt {
  public: 
    Identifier* variable;
    Expr* init;
    LetStmt(Identifier* variable, Expr* init = nullptr):
      Stmt(AstNode::Type::LetStmt),
      variable{variable},
      init{init}
       {}
    ~LetStmt() override;

};
class ReturnStmt: public Stmt {
  public:
    Expr* argument;
    ReturnStmt(Expr* argument):
      Stmt(AstNode::Type::ReturnStmt),
      argument{argument} {

      }
   ~ReturnStmt() override ;
};

class NumericLiteral: public Expr {
  public:
    std::string_view raw;
    NumericLiteral(std::string_view raw):
      Expr(AstNode::Type::NumericLiteral),
      raw{raw} {

      }
    ~NumericLiteral()override;
};
class FunctionDeclaration: public Stmt {
  public:
    Identifier* identifier;
    Vector<Identifier*> parameters;
    BlockStmt* body;
    bool is_async;
    FunctionDeclaration(Identifier* identifier,
                        Vector<Identifier*>& parameters,
                        BlockStmt* body,
                        bool is_async=false):
      Stmt(AstNode::Type::FunctionDeclaration),
      identifier{identifier},
      parameters{std::move(parameters)},
      body{std::move(body)},
      is_async{is_async}
  {}
  ~FunctionDeclaration() override;
};
