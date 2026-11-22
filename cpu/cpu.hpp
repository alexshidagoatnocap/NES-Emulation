#pragma once

#include "cpu_helpers.hpp"

namespace NES {

class CPU {
public:
  void lda(Byte byteToLoad);
  void ldx(Byte byteToLoad);
  void ldy(Byte byteToLoad);
  Byte sta(Byte address);
  Byte stx(Byte address);
  Byte sty(Byte address);

private:
  Registers registers{};
  CPUHelpers helpers{};
};

} // namespace NES
