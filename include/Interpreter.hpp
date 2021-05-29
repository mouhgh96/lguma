/* #pragma once
#include "Ast.hpp"
#include "Env.hpp"
#include "Heap.hpp"
#include <set>


template<typename T>
using Set = std::set<T>;
struct Interpreter {
  Interpreter(Env *global_env = nullptr)
      :  global_env{global_env},
    heap{*this} {};
  Set<Value*> roots;
  Env *global_env;
  Heap heap;
  
}; */
