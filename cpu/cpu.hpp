#pragma once

#include "type-aliases.hpp"

// TODO: Remove later, testing if includes work
void helloFromCpu();

namespace NES {

class CPU {
public:
  void lda(Byte byteToLoad);
  void ldx(Byte byteToLoad);
  void ldy(Byte byteToLoad);
  Byte sta(Byte byteToLoad);
  Byte stx(Byte byteToLoad);
  Byte sty(Byte byteToLoad);

private:
  struct Registers {
    Word PC;
    Byte SP;
    Byte A;
    Byte X;
    Byte Y;
    Byte P;
  };

  Registers registers{};

  enum StatusFlags {
    CARRY = 0,
    ZERO = 1,
    INTERRUPT_DISABLE = 2,
    DECIMAL = 3,
    B = 4,
    OVERFLOW = 6,
    NEGATIVE = 7
  };

  inline bool checkByteIfNegative(Byte b) {
    if (b >> StatusFlags::NEGATIVE)
      return true;

    return false;
  }

  inline bool checkByteIfZero(Byte b) {
    bool flag = (b & StatusFlags::ZERO) >> StatusFlags::ZERO;

    if (flag)
      return true;

    return false;
  }

  inline void setFlag(StatusFlags flag) { registers.P |= (1 << flag); }

  inline void resetFlag(StatusFlags flag) { registers.P &= ~(1 << flag); }

  inline void checkAndSetNegativeAndZeroFlag(Byte b) {
    if (checkByteIfNegative(b))
      setFlag(StatusFlags::NEGATIVE);
    else
      resetFlag(StatusFlags::NEGATIVE);

    if (checkByteIfZero(b))
      setFlag(StatusFlags::ZERO);
    else
      resetFlag(StatusFlags::ZERO);
  }
};

} // namespace NES
