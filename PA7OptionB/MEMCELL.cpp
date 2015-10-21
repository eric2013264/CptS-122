#include "CPUEMU.h"

MemoryCell::operator CPUFLOAT(void)
{
	CPUFLOAT f;
	UCPUWORD *p=(UCPUWORD *)&f;
	for (int i = 0 ; i < sizeof(CPUFLOAT)/sizeof(CPUWORD); i++ )
		p[i] = (UCPUWORD)(*MemoryCell::Memory)[Address() + i ];
	return f;
}

MemoryCell &MemoryCell::AssignFloat(CPUFLOAT f)
{
	UCPUWORD *p = (UCPUWORD *)&f;
	for (int i = 0 ; i < sizeof(CPUFLOAT)/sizeof(CPUWORD) ; i++ )
		(*MemoryCell::Memory)[Address() + i ] = p[i];
	return *this;
}