#pragma once
#include <cstdint>
#include <fmt/core.h>
#include <vector>
#include <array>
#include "Register.hpp"
#include "cdefs.hpp"
#include "OpCode.hpp"
template<typename T>
using Vector = std::vector<T>;
template<typename T, std::size_t N>
using FixedArray = std::array<T, N>;

template<typename T, std::size_t N>
struct Stack {
  FixedArray<T, N> data;
  std::size_t current_index {0};

  std::size_t push(T val) {
    if(current_index >= N) {
      fmt::print("error stack overflow\n");
      return N;
    }
    data[current_index] = val;
    return current_index++;
  }
  T pop() {
    if(current_index == 0) {
      fmt::print("error stack underflow\n");
      return N;
    }
    return data[--current_index];
  }
};
struct Vm {
  static constexpr auto max_stack_size = 128;
  Vector<std::uint8_t> machine_code; 
  Stack<std::uintptr_t,128> stack;
  std::size_t current_index{0};
  FixedArray<std::uintptr_t, REGISTER_NBR> registers;
  NON_COPYABLE(Vm);

  Vm() = default;
  void insert_byte(std::uint8_t byte) ;
  void insert_byte(const OpCode byte) ;

  void insert_add(std::uint8_t dist, std::uint8_t src) ;
  std::uint8_t get_current() {
    return machine_code[current_index];
  }
  void advance(std::uint8_t increment = 1) {
    current_index += increment;
  }
  void push(std::uintptr_t val) ;
  std::uintptr_t pop() ;
  void run() {
    auto expr = 1 + 3;
    /*
       pop Rbx
       pop Rax
       add Rax, Rbx
       print Rax
       */
    push(1);
    push(3);
    insert_byte(OpCode::Pop);
    insert_byte(Rbx);
    insert_byte(OpCode::Pop);
    insert_byte(Rax);
    insert_add(Rax, Rbx);
    insert_byte(OpCode::Print);
    auto size = machine_code.size();
    while(current_index < size) {
      switch(auto op = static_cast<OpCode>(get_current())) {
        case OpCode::Pop: {
          advance(); 
          auto rgs = get_current();
          registers[rgs] = pop();
          fmt::print("rgs_{} = {}\n", rgs, registers[rgs]);
          advance();
        } break;
        case OpCode::Add: {
          advance();
          auto rgs = get_current();
          auto dist = rgs >> 4;
          auto src = rgs & 0b111;
          registers[dist] += registers[src];
          advance();
        } break;
        case OpCode::Print: {
          advance();
          fmt::print("Rax : {}\n",  registers[Rax]);
        } break;
        default: {
          fmt::print("unimplemented opCode {}\n", op);
          return;
        };

      } 
    }
    // insert_byte(Rax);
  }
};
