#include "Value.hpp"


  bool Value::is_garbage_collected() const {
    return type == Type::String || type == Type::Table ||
        type == Type::Function;
  }
  GCObject* Value::get_gc_object() const {
    return obj.gc;
  }
