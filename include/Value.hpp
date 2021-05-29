#pragma once
#include<cstdint>
#include "Forward.hpp"
#include "cdefs.hpp"


struct Value {
  //  NON_COPYABLE(Value)


  using number_type = double;
  enum Type {
    Nil = 0,
    Boolean = 1,
    Number = 2,
    Table = 3,
    Function = 4,
    String = 5,
  };
  union {
    void* user_data;
    GCObject* gc;
    bool b;
    number_type number;
  } obj;
  Type type{Nil};
  bool is_garbage_collected() const ;
  GCObject* get_gc_object() const ;
};
