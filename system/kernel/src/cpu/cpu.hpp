
#ifndef CPU_CPU_H
#define CPU_CPU_H


namespace CPU
{
	typedef struct{
		uint64_t rax;
		uint64_t rbx;
		uint64_t rcx;
		uint64_t rdx;
		uint64_t rsi;
		uint64_t rdi;
		uint64_t r8;
		uint64_t r9;
		uint64_t r10;
		uint64_t r11;

		uint64_t   rip;
		uint64_t   cs;
		uint64_t   rflags;
		uint64_t   rsp;
		uint64_t   ss;
	} __attribute__((__packed__)) State;
}

#endif