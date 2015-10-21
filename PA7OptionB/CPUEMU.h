#ifndef __CPUEMU_H
#define __CPUEMU_H

#include <iostream>
#include <iomanip>
#include <limits.h>
#include <fstream>
using namespace std;

class Instruction;
class CPU;
class MemoryCell;
class Computer;

typedef short int CPUWORD;
typedef unsigned short int UCPUWORD;
typedef unsigned short int MEMORYADDR;
typedef unsigned char OpCode;
typedef float CPUFLOAT;

#define OPCODE_BITS 5
#define MEMORYADDR_BITS (sizeof(CPUWORD)*CHAR_BIT-OPCODE_BITS)
#define MEMORYSIZE (1<<MEMORYADDR_BITS)
#define ENCODE(op, addr) ((op)<<((sizeof(CPUWORD)*CHAR_BIT)-OPCODE_BITS))|((addr)&(0xffff>>OPCODE_BITS));
#define ILLEGALOP ((OpCode)(-1))
#define BITMASK ((UCPUWORD)(-1))
#define MAXSTRLENGTH 255

enum OPERANDTYPE
{
	NONE,
	UNARY,
	BINARY
};

enum ERRCODE
{
	OK=0,
	CANCEL,
	ERRMSG_START=2,
	DIVIDEBYZERO=2
};

template <class T>
class Register
{
	public:
		Register(T Value=0) {Value_=Value;}
		Register(const Register &r) {Value_=r.Value;}
		Register &operator ++(int) {++Value_; return *this;}
		Register &operator ++(void) {++Value_; return *this;}
		Register &operator +=(T c) {Value_+=c; return *this;}
		Register &operator -=(T c) {Value_-=c; return *this;}
		Register &operator *=(T c) {Value_*=c; return *this;}
		Register &operator /=(T c) {Value_/=c; return *this;}
		operator T (void) {return Value_;}
		virtual Register &operator = (const T w) {Value_=w; return *this;}

	protected:
		T Value_;
};

struct InstructionEntry
{
	OpCode Code;
	Instruction *OpInst;
	OPERANDTYPE OperandType;
};

class Instruction
{
	public:
		virtual ERRCODE Execute(CPU &, MemoryCell *) {return CANCEL;}
		virtual const char *GetSymbolicName(void) {return 0;}

	protected:
		void CheckZeroFlag(CPU &cpu);
		void CheckNegFlag(CPU &cpu);
		Register<CPUWORD> &Acc(CPU &cpu);
		Register<CPUFLOAT> &FloatAcc(CPU &cpu);
		Register<UCPUWORD> &PC(CPU &cpu);
		Register<char> &NFlag(CPU &cpu);
		Register<char> &ZFlag(CPU &cpu);
};

class InstructionLookup
{
	public:
		InstructionLookup(void);
		Instruction *Search(OpCode op);
		int Search(const char *OpcodeName, OpCode &op, OPERANDTYPE &optype);
		~InstructionLookup(void);

};

extern InstructionLookup InstructionTable;

#define OP(_class) _class##_
#define DEFINE_OP(_class, _symname)\
class _class: public Instruction\
{\
	public:\
		virtual ERRCODE Execute(CPU &, MemoryCell *);\
		virtual const char *GetSymbolicName(void) { return _symname;}\
};\
extern _class OP(_class);

#define IMPLEMENT_OP(_class)\
_class OP(_class);

DEFINE_OP(AddOp,"ADD");
DEFINE_OP(SubOp,"SUB");
DEFINE_OP(StoreOp,"STORE");
DEFINE_OP(LoadOp,"LOAD");
DEFINE_OP(BranchNegOp,"BRN");
DEFINE_OP(BranchOp,"BR");
DEFINE_OP(BranchZeroOp,"BRZ");
DEFINE_OP(ClearAccOp,"CLR");
DEFINE_OP(OutputOp,"OUTPUT");
DEFINE_OP(InputOp,"INPUT");
DEFINE_OP(MultOp,"MUL");
DEFINE_OP(DivOp,"DIV");
DEFINE_OP(HaltOp,"HLT");
DEFINE_OP(OutputStrOp,"OUTPUTS");
DEFINE_OP(InputStrOp,"INPUTS");
DEFINE_OP(NewLineOp,"NEWLINE");
DEFINE_OP(ExptOp,"EXPT");
DEFINE_OP(ModOp,"MOD");
DEFINE_OP(LoadFloatOp,"LOADF");
DEFINE_OP(StoreFloatOp,"STOREF");
DEFINE_OP(AddFloatOp,"ADDF");
DEFINE_OP(SubFloatOp,"SUBF");
DEFINE_OP(MultFloatOp,"MULF");
DEFINE_OP(DivFloatOp,"DIVF");
DEFINE_OP(InputFloatOp,"INPUTF");
DEFINE_OP(OutputFloatOp,"OUTPUTF");

class MemoryCell
{
	friend class Computer;
	public:
		MemoryCell(void) {Cell_=0;}
		MEMORYADDR Address(void) {return this-Memory[0];}
		MemoryCell &operator =(CPUWORD c) {Cell_=c; return *this;}
		MemoryCell &AssignFloat(CPUFLOAT f);
		operator CPUWORD(void) {return Cell_;}
		operator UCPUWORD(void) {return Cell_;}
		operator CPUFLOAT(void);
		static void SetBaseMemoryAddr (MemoryCell **m) {Memory = m;}
	private:
		CPUWORD Cell_;
		static MemoryCell **Memory;
};

class CPU
{
	friend class Instruction;
	friend class Computer;
	public:
		CPU(Computer &Machine);

	void Halt(int Flag=1);
	private:
		void Cycle(void);
		Register<CPUWORD> Acc;
		Register<CPUFLOAT> FloatAcc;
		Register<UCPUWORD> PC,GP,OperandReg;
		Register<OpCode> OpCodeReg;
		Register<char> NFlag, ZFlag;
		Computer &Machine;
		int HaltFlag;
};

class Computer
{
	friend class CPU;
	public:
		Computer(void);
	void Begin(istream &input);
		~Computer(void);
	protected:
		void Coredump(void);
		CPU Processor;
		MemoryCell *Memory;
};

inline void Instruction ::CheckZeroFlag(CPU &cpu)
{
	if (!cpu.Acc)
		cpu.ZFlag=1;
	else
		cpu.ZFlag=0;
}

inline void Instruction::CheckNegFlag(CPU &cpu)
{
	if (cpu.Acc<0)
		cpu.NFlag=1;
	else
		cpu.NFlag=0;
}

inline Register<CPUWORD> &Instruction::Acc(CPU &cpu)
{
	return cpu.Acc;
}

inline Register<char> &Instruction::NFlag(CPU &cpu)
{
	return cpu.NFlag;
}

inline Register<char> &Instruction::ZFlag(CPU &cpu)
{
	return cpu.ZFlag;
}

inline Register<UCPUWORD> &Instruction::PC(CPU &cpu)
{
	return cpu.PC;
}

inline Register<CPUFLOAT> &Instruction::FloatAcc(CPU &cpu)
{
	return cpu.FloatAcc;
}

#endif
