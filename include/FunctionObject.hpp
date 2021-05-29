
#include "Ast.hpp"
#include "Forward.hpp"
#include "GCObject.hpp"
#include <string_view>
#include <vector>

template<typename T>
using Vector = std::vector<T>;

struct FunctionObject: public GCObject {
  Vector<std::string_view> params;
  BlockStmt* fn_ast;
  Env* env;
  FunctionObject(Env* env,BlockStmt* fn_ast):
    fn_ast(fn_ast) {

    }
};
