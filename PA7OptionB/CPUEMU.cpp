#include <fstream>
#include "CPUEMU.h"

static const char *ErrorMsg[]=
{
	"Divide by zero error"
};

MemoryCell **MemoryCell::Memory;

Computer::Computer(void):Processor(*this)
{
	Memory = new MemoryCell[MEMORYSIZE];
	MemoryCell::Memory=&Memory;
}

void Computer::Coredump(void)
{
	Register<UCPUWORD> StartDump;
	const int MAXBYTESDUMPED=140;
	int Counter=0;
	if (Processor.PC<10)
		StartDump=0;
	else
		StartDump=Processor.PC-10;
	cerr <<"Coredump:" << endl;
	while (Counter<MAXBYTESDUMPED && StartDump<MEMORYSIZE)
	{
		cerr<<setfill('0')<<setw(4)<<hex<<StartDump<<' ';
		for (int i=0; i<14 && Counter<MAXBYTESDUMPED && StartDump <MEMORYSIZE;
			i++,Counter++, StartDump++)
				cerr<< setw(4) <<setfill('0')<< (UCPUWORD)Memory[StartDump]<<' ';
			cerr<<endl;
	}

	cerr<<endl;
	cerr<< "PC: " <<setw(4) <<setfill('0') <<Processor.PC<< ' ';
	cerr<< "Acc: " <<setw(4) <<setfill('0') <<Processor.Acc<< ' ';
	cerr<< "FAcc: " <<Processor.FloatAcc <<' ';
	int ZFlag, NFlag;
	ZFlag=(char)Processor.ZFlag;
	NFlag=(char)Processor.NFlag;
	cerr<<setw(1) << dec
		<<"Z: " << ZFlag << ' '
		<<"N: " << NFlag << endl;
}

void Computer::Begin(istream &input)
{
	UCPUWORD Counter=0;
	while (!input.eof())
	{
		UCPUWORD w;
		char LookAhead;
		input >> LookAhead;		if (input.fail())
			break;
		switch (LookAhead)
		{
			case '@':
			{
				UCPUWORD NewAddress;
				input >> hex >> NewAddress;
				if (NewAddress>=MEMORYSIZE)
				{
					cerr << "Invalid address. Simulator terminated." <<endl;
					return;
				}
				Counter= NewAddress;
				break;
			}

			case '&':
			{
				CPUFLOAT f;
				input >> dec >>f;
				if (input.bad())
				{
					cerr << "Invalid floating point number." <<endl;
					return;
				}
				Memory[Counter].AssignFloat(f);
				Counter+=sizeof(CPUFLOAT)/sizeof(CPUWORD);
				break;
			}

			default:
				input.putback(LookAhead);
				input >> hex >> w;
				if (w == 0xffff)
					break;
				Memory[Counter++]=w;
//				cout<<hex<<w<<endl;
				break;
		}
		
    }
	//	cout<<BITMASK<<" "<<ILLEGALOP<<endl;
		cout<< "program starts... "<<endl;
		while (!Processor.HaltFlag)
			Processor.Cycle();
		if (Processor.HaltFlag==-1)
			Coredump();
		else cout<< "Program terminated normally." << endl;
}
	Computer::~Computer(void)
	{
		delete [] Memory;
	}

	CPU::CPU(Computer &comp):Machine(comp)
	{
		HaltFlag=0;
		ZFlag=0;
		NFlag=0;
	}

	void CPU::Cycle(void)
	{
		GP=Machine.Memory[PC];
//cout<<hex<<(UCPUWORD) (GP)<<" ";
		OpCodeReg=(UCPUWORD) (GP) >> (sizeof(CPUWORD)*CHAR_BIT-OPCODE_BITS);
//cout<<hex<<(UCPUWORD) (OpCodeReg)<<" ";
		OperandReg=(UCPUWORD) (GP) & (BITMASK>>OPCODE_BITS);
//cout<<hex<<(UCPUWORD) (OperandReg)<<"\t";
		PC+=1;

		Instruction *i=InstructionTable.Search(OpCodeReg);
		if(!i)
		{
			cerr<< "Invalid opcode at location "
				<< setw(4) << setfill('0') << hex << PC-1
				<< ". Program aborted." << endl <<endl;
			Halt(-1);
		}else{
			ERRCODE ErrCode;
			if (( ErrCode=i->Execute(*this, &Machine.Memory[OperandReg]))>=ERRMSG_START)
			{
				cerr<< "An error occured when executing the opcode "
					<< i->GetSymbolicName() << "at location"
					<< setw(4) << setfill('0') << hex <<PC-1 <<endl
					<<ErrorMsg[ErrCode-ERRMSG_START] << endl <<endl;
				Halt(-1);
			}
		}
	}

	void CPU::Halt(int Flag)
	{
		HaltFlag=Flag;
	}


