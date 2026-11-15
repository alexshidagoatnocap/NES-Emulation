#pragma once

#include "cpu_helpers.hpp"
#include "cpu_types.hpp"
#include "type-aliases.hpp"

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
  Registers registers{};
  CPUHelpers helpers{};
};

} // namespace NES
