#pragma once
#include <string_view>
#include <unordered_map>
#include "Value.hpp"

class GCObject {

 public:
  void visit() {
    is_marked = true;
    for(auto&[_, value]: m_propreties)
      {
        if(value != nullptr && value->is_garbage_collected())
          {
            value->get_gc_object()->visit();
          }
      }
  }
private:
  bool is_marked;
  std::unordered_map<std::string_view, Value*> m_propreties;
};
