#pragma once

#include "type-aliases.hpp"

namespace NES {

struct Registers {
  Word PC;
  Byte SP;
  Byte A;
  Byte X;
  Byte Y;
  Byte P;
};

enum StatusFlags {
  CARRY = 0,
  ZERO = 1,
  INTERRUPT_DISABLE = 2,
  DECIMAL = 3,
  B = 4,
  OVERFLOW = 6,
  NEGATIVE = 7
};

} // namespace NES
