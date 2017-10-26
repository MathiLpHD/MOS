
//Library Includes:

//#include <libMOS.hpp> //TODO: Get the link to the lib working

//Kernel Includes:

#include "idt.hpp"
#include "gdt.hpp"
#include "tss.hpp"

#include <cpu/cpu.hpp>
#include <cpu/CPUID.hpp>
#include <cpu/msr.hpp>
#include <driver/keyboard/ps2/keyboard.hpp>
#include <interrupt/init.hpp>
#include <keys/keys.hpp>
#include <libMOS/convert/convert.hpp>
#include <mm/vmm.hpp>
#include <multiboot.hpp>
#include <syscall/syscall.hpp>
#include <terminal/console.hpp>
#include <terminal/shell.hpp>

#include <common.hpp>

namespace System
{
	extern "C"
	{
		void Init(uint32_t magic, multiboot_t *multiboot)
		{
			Paging::Init();
			multiboot = Paging::ToVMA_V(multiboot);

			CPU::InitBSP();

			CPUID::GetCPUInfo();
			Console::Init();

			Interrupt::Init();

			IDT::Init();
			GDT::Init();
			TSS::Init();

			CPUID::GetCPUInfo();

			Driver::Keyboard::Init();
			Keys::Init();
			Syscall::Init();

			asm volatile("sti");

			Shell::Init();

			while (true)
			{
				asm volatile("hlt");
			}
		}
	}
}