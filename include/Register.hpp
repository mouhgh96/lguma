#include <cstdint>


enum Register: std::uint8_t {
  Rax ,
  Rbx ,
  Rcx ,
  Rdx ,
  Rsi ,
  Rdi ,
};
inline constexpr auto REGISTER_NBR = 6;
