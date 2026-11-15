#pragma once

#include "type-aliases.hpp"

// TODO: Remove later, testing if includes work
void helloFromCpu();

namespace NES {

class CPU {
public:
  struct Registers {
    Word PC;
    Byte SP;
    Byte A;
    Byte X;
    Byte Y;
    Byte P;
  };

  Registers registers{};

  void lda(Byte byteToLoad) {
    registers.A = byteToLoad;

    if (checkIfZero(registers.A)) {
    }
  }

private:
  enum StatusFlags {
    CARRY = 0,
    ZERO = 1,
    INTERRUPT_DISABLE = 2,
    DECIMAL = 3,
    B = 4,
    OVERFLOW = 6,
    NEGATIVE = 7
  };

  bool checkIfNegative(Byte b) {
    if (b >> StatusFlags::NEGATIVE)
      return true;

    return false;
  }

  bool checkIfZero(Byte b) {
    bool flag = (b & StatusFlags::ZERO) >> StatusFlags::ZERO;

    if (flag)
      return true;

    return false;
  }
};

} // namespace NES
