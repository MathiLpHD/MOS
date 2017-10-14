
#include <terminal/text.hpp>
#include <interrupt/handler/stubs.hpp>
#include <interrupt/init.hpp>


__attribute__((interrupt)) void LVT_Timer(CPU::State *state)
{
	Interrupt::APIC::Write(APIC_EOI, 0);
}