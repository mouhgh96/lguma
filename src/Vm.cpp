#include "Vm.hpp"

void Vm::insert_byte(std::uint8_t byte) { machine_code.push_back(byte); }

void Vm::insert_byte(const OpCode byte) {
  machine_code.push_back(static_cast<std::uint8_t>(byte));
}
void Vm::insert_add(std::uint8_t dist, std::uint8_t src) {
  machine_code.push_back(static_cast<std::uint8_t>(OpCode::Add));
  std::uint8_t bottom_mask = 0b111;
  machine_code.push_back((dist << 4) | (src & bottom_mask));
}

void Vm::push(std::uintptr_t val) { stack.push(val); }
std::uintptr_t Vm::pop() { return stack.pop(); }
