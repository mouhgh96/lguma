#pragma once
#include "Forward.hpp"
#include <cstdlib>
#include <vector>
#include <utility>
#include <fmt/core.h>
template<typename T>
using Vector = std::vector<T>;

using HeapBlock = std::pair<void*, void*>;
struct Heap  {
  
  Vector<HeapBlock> arena;
  template<typename T, typename... Args>
    T* make(Args&&... args) {
      auto mem = std::malloc(sizeof(T));
      fmt::print("sizeof Value = {}\n", sizeof(T));
      auto ptr =new (mem) T(std::forward<Args>(args)...);
      arena.emplace_back(mem, ptr);
      return ptr;
    }
  void free(void* ptr) {
    std::free(ptr);
  }
  ~Heap() {
    fmt::print("desctructor called for Heap \n");
    for(auto& p: arena) {
      fmt::print("free {}\n",p.first
                 );
      std::free(p.first);
    }
  }
  
};
