#include "cpu.hpp"

#include <print>

void helloFromCpu() { std::println("Hello from cpu!"); }

namespace NES {

void CPU::lda(Byte byteToLoad) {
  registers.A = byteToLoad;
  helpers.checkAndSetNegativeAndZeroFlag(registers, byteToLoad);
}

void CPU::ldx(Byte byteToLoad) {
  registers.X = byteToLoad;
  helpers.checkAndSetNegativeAndZeroFlag(registers, byteToLoad);
}

void CPU::ldy(Byte byteToLoad) {
  registers.Y = byteToLoad;
  helpers.checkAndSetNegativeAndZeroFlag(registers, byteToLoad);
}

Byte CPU::sta(Byte byteToLoad) { return registers.A; }

Byte CPU::stx(Byte byteToLoad) { return registers.X; }

Byte CPU::sty(Byte byteToLoad) { return registers.Y; }

} // namespace NES
