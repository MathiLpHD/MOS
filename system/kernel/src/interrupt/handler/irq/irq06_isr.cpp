
#include <terminal/text.hpp>
#include <interrupt/handler/stubs.hpp>


__attribute__((interrupt)) void IRQ_06(CPU::State *state)
{
	//Text::Clear();
	Text::WriteLine("IRQ_06!");
}