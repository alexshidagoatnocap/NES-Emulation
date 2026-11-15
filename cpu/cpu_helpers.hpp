#pragma once

#include "cpu_types.hpp"
#include "type-aliases.hpp"

namespace NES {

struct CPUHelpers {
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

  inline void setFlag(Registers &regs, StatusFlags flag) {
    regs.P |= (1 << flag);
  }

  inline void resetFlag(Registers &regs, StatusFlags flag) {
    regs.P &= ~(1 << flag);
  }

  inline void checkAndSetNegativeAndZeroFlag(Registers &regs, Byte b) {
    if (checkByteIfNegative(b))
      setFlag(regs, StatusFlags::NEGATIVE);
    else
      resetFlag(regs, StatusFlags::NEGATIVE);

    if (checkByteIfZero(b))
      setFlag(regs, StatusFlags::ZERO);
    else
      resetFlag(regs, StatusFlags::ZERO);
  }
};

} // namespace NES
