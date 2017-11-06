
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
#include <libMOS/base/string.hpp>
#include <mm/vmm/init.hpp>
#include <mm/vmm/conv.hpp>
#include <mm/heap/init.hpp>
#include <mm/heap/heap.hpp>
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
			multiboot = VMM::ToVMA_V(multiboot);
			VMM::Init();
			Heap::Init();

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

			string sTest;
			sTest = "Hallo";
			Shell::WriteLine(sTest);
			sTest += " Welt!";
			Shell::WriteLine(sTest);
			string sTest2 = " Das ist mein OS!";
			sTest = sTest + sTest2;
			Shell::WriteLine(sTest);
			sTest += " Dieser Text wurde mit Strings erstellt!";
			Shell::WriteLine(sTest);
			sTest += " ==> malloc funkt!-------------";
			Shell::WriteLine(sTest);
			char cTest[64];
			Convert::ToString((uint64_t)&_end, cTest, 16);
			Shell::WriteLine(cTest);
			char *cTest2 = sTest;
			Convert::ToString(((uint64_t)cTest2) + strlen(sTest) - 1, cTest, 16);
			Shell::WriteLine(cTest);
			cTest2 += strlen(sTest) - 1;
			Shell::Write(cTest2);
			
			while (true)
			{
				asm volatile("hlt");
			}
		}
	}
}