#include "CPUEMU.h"
#include <cstring>

IMPLEMENT_OP(AddOp);
ERRCODE AddOp::Execute(CPU &cpu, MemoryCell *operand)
{
	Acc(cpu) += operand[0];
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(SubOp);
ERRCODE SubOp::Execute(CPU &cpu, MemoryCell *operand)
{
	Acc(cpu) -= operand[0];
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(StoreOp);
ERRCODE StoreOp::Execute(CPU &cpu, MemoryCell *operand)
{
	operand[0] = Acc(cpu);
	return OK;
}

IMPLEMENT_OP(LoadOp);
ERRCODE LoadOp::Execute(CPU &cpu, MemoryCell *operand)
{
	Acc(cpu) = operand[0];
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(BranchOp);
ERRCODE BranchOp::Execute(CPU &cpu, MemoryCell *operand)
{
	PC(cpu) = operand[0].Address();
	return OK;
}

IMPLEMENT_OP(BranchZeroOp);
ERRCODE BranchZeroOp::Execute(CPU &cpu, MemoryCell *operand)
{
	if (ZFlag(cpu))
	{
		PC(cpu) = operand[0].Address();
		return OK;
	}	else return CANCEL;
}

IMPLEMENT_OP(BranchNegOp);
ERRCODE BranchNegOp::Execute(CPU &cpu, MemoryCell *operand)
{
	if (NFlag(cpu))
	{
		PC(cpu) = operand[0].Address();
		return OK;
	}	else return CANCEL;
}

IMPLEMENT_OP(HaltOp);
ERRCODE HaltOp::Execute(CPU &cpu, MemoryCell *)
{
	cpu.Halt();
	return OK;
}

IMPLEMENT_OP(InputOp);
ERRCODE InputOp::Execute(CPU &, MemoryCell *cell)
{
	CPUWORD c;
	cin >> c;
	if (!cin || cin.bad())
	{
		cin.clear();
		cin.ignore(MAXSTRLENGTH,'\n');
		return CANCEL;
	}
	*cell = c ;
	return OK ;
}

IMPLEMENT_OP(OutputOp);
ERRCODE OutputOp::Execute(CPU &, MemoryCell *cell)
{
	cout << (CPUWORD)*cell;
	return OK;
}

IMPLEMENT_OP(MultOp);
ERRCODE MultOp::Execute(CPU &cpu, MemoryCell *cell)
{
	Acc(cpu) *= *cell;
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(ClearAccOp);
ERRCODE ClearAccOp::Execute(CPU &cpu, MemoryCell *)
{
	Acc(cpu) = 0 ;
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(DivOp);
ERRCODE DivOp::Execute(CPU &cpu, MemoryCell *cell)
{
	if (!(UCPUWORD)*cell)
		return DIVIDEBYZERO;
	Acc(cpu) /= *cell;
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(OutputStrOp);
ERRCODE OutputStrOp::Execute(CPU &, MemoryCell *cell)
{
	int StrLength = ((UCPUWORD)(*cell) >> (sizeof(UCPUWORD)/2*CHAR_BIT));
	for (int i = 0 ; i < StrLength ; i++)
	{
		char ch;
		if ( i % 2 == 0)
		{
			ch = ((UCPUWORD)(*cell)) & (BITMASK >> (sizeof(UCPUWORD)/2*CHAR_BIT));
			cell++;
		} else
			ch = ((UCPUWORD)(*cell)) >>(sizeof(UCPUWORD)/2*CHAR_BIT);
		cout << ch;
	}
	return OK;
}

IMPLEMENT_OP(InputStrOp);
ERRCODE InputStrOp::Execute(CPU &, MemoryCell *cell)
{
	char str[MAXSTRLENGTH];
	cin.getline(str, MAXSTRLENGTH);
	if (!cin)
		return CANCEL;
	char len = strlen(str);
	*cell = 0;
	*cell = (UCPUWORD)(len << (sizeof(UCPUWORD)/2*CHAR_BIT));
	for (int i = 0 ; i < len ; i++)
	{
		if ( i%2 == 0)
		{
			*cell = (UCPUWORD)(*cell)|(str[i]);
			cell++;
			*cell = 0;
		} else
			*cell = (UCPUWORD)(*cell)|(str[i] << (sizeof(UCPUWORD)/2*CHAR_BIT));
	}
	return OK;
}

IMPLEMENT_OP(NewLineOp);
ERRCODE NewLineOp::Execute(CPU &, MemoryCell *)
{
	cout << endl;
	return OK;
}

static CPUWORD Pow(CPUWORD Base, UCPUWORD Exp)
{
	if (Exp == 0)
		return 1 ;
	else
	{
		CPUWORD Result = Base;
		for (UCPUWORD i = 0 ; i < Exp-1 ; i++)
			Result *= Base;
		return Result;
	}
}

IMPLEMENT_OP(ExptOp);
ERRCODE ExptOp::Execute(CPU &cpu, MemoryCell *cell)
{
	Acc(cpu) = Pow(Acc(cpu), *cell);
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(ModOp);
ERRCODE ModOp::Execute(CPU &cpu, MemoryCell *cell)
{
	if (!(UCPUWORD)*cell)
		return DIVIDEBYZERO;
	Acc(cpu) = Acc(cpu) % (UCPUWORD)(*cell);
	CheckZeroFlag(cpu);
	CheckNegFlag(cpu);
	return OK;
}

IMPLEMENT_OP(LoadFloatOp);
ERRCODE LoadFloatOp::Execute(CPU &cpu, MemoryCell *cell)
{
	FloatAcc(cpu) =*cell;
	return OK;
}

IMPLEMENT_OP(StoreFloatOp);
ERRCODE StoreFloatOp::Execute(CPU &cpu, MemoryCell *cell)
{
	cell->AssignFloat(FloatAcc(cpu));
	return OK;
}

IMPLEMENT_OP(AddFloatOp);
ERRCODE AddFloatOp::Execute(CPU &cpu, MemoryCell *cell)
{
	FloatAcc(cpu) += (CPUFLOAT)*cell ;
	return OK;
}

IMPLEMENT_OP(SubFloatOp);
ERRCODE SubFloatOp::Execute(CPU &cpu, MemoryCell *cell)
{
	FloatAcc(cpu) -= (CPUFLOAT)*cell ;
	return OK;
}

IMPLEMENT_OP(MultFloatOp);
ERRCODE MultFloatOp::Execute(CPU &cpu, MemoryCell *cell)
{
	FloatAcc(cpu) *= (CPUFLOAT)*cell ;
	return OK;
}

IMPLEMENT_OP(DivFloatOp);
ERRCODE DivFloatOp::Execute(CPU &cpu, MemoryCell *cell)
{
	if ((CPUFLOAT)*cell == 0.0)
		return DIVIDEBYZERO;
	FloatAcc(cpu)/=(CPUFLOAT)*cell;
	return OK;
}

IMPLEMENT_OP(InputFloatOp);
ERRCODE InputFloatOp::Execute(CPU &, MemoryCell *cell)
{
	CPUFLOAT c;
	cin >> c;
	if (!cin)
		return CANCEL;
	cell->AssignFloat(c);
	return OK;
}

IMPLEMENT_OP(OutputFloatOp);
ERRCODE OutputFloatOp::Execute(CPU &, MemoryCell *cell)
{
	cout << (CPUFLOAT)*cell;
	return OK;
}