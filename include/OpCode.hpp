#pragma
#include <cstdint>

enum class OpCode : std::uint8_t {
  Add,
  Sub,
  Mult,
  Div,
  PushRegister,
  PushConstant,
  Pop,
  Print,
};
