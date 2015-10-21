#include "CPUEMU.h"
#include <string.h>

#define ENTRY(id,OpName,OpType) {id,&OP(OpName),OpType}
// constant array containing the opcodes and their respective instruction
// clases.
static const InstructionEntry _InstructionTable[]=
{
ENTRY(1,LoadOp,UNARY),
ENTRY(2,StoreOp,UNARY),
ENTRY(3,AddOp,UNARY),
ENTRY(4,SubOp,UNARY),
ENTRY(5,DivOp,UNARY),
ENTRY(6,BranchNegOp,UNARY),
ENTRY(7,BranchOp,UNARY),
ENTRY(8,BranchZeroOp,UNARY),
ENTRY(9,BranchOp,UNARY),
ENTRY(10,OutputOp,UNARY),
ENTRY(11,InputOp,UNARY),
ENTRY(12,OutputStrOp,UNARY),
ENTRY(13,InputStrOp,UNARY),
ENTRY(14,NewLineOp,NONE),
ENTRY(15,ClearAccOp,NONE),
ENTRY(16,ModOp,UNARY),
ENTRY(17,ExptOp,UNARY),
ENTRY(18,LoadFloatOp,UNARY),
ENTRY(19,StoreFloatOp,UNARY),
ENTRY(20,AddFloatOp,UNARY),
ENTRY(21,SubFloatOp,UNARY),
ENTRY(22,MultFloatOp,UNARY),
ENTRY(23,DivFloatOp,UNARY),
ENTRY(24,OutputFloatOp,UNARY),
ENTRY(25,InputFloatOp,UNARY),
ENTRY(0,HaltOp,NONE)
};
#define INSTRUCTIONTABLE_SIZE (sizeof(_InstructionTable)/sizeof(InstructionEntry))

InstructionLookup InstructionTable;

InstructionLookup::InstructionLookup(void)
{
}

Instruction *InstructionLookup::Search(OpCode op)
{
//cout<<"hex:"<<hex<<(UCPUWORD) (op)<<" ";
//cout<<"dec:"<<dec<<(UCPUWORD) (op)<<" "<<endl;
	for (unsigned int i=0; i<INSTRUCTIONTABLE_SIZE;i++)
	{
		if (_InstructionTable[i].Code==op)
			return _InstructionTable[i].OpInst;
	}
	return NULL;
}

int InstructionLookup::Search(const char *OpSymName, OpCode &op, OPERANDTYPE &optype)
{
	for (unsigned int i=0; i<INSTRUCTIONTABLE_SIZE;i++)
	{
		if (!strcmp(_InstructionTable[i].OpInst->GetSymbolicName(),OpSymName))
		{
			op=_InstructionTable[i].Code;
			optype=_InstructionTable[i].OperandType;
			return 1;
		}
	}
	return 0;
}

InstructionLookup::~InstructionLookup(void)
{
}



