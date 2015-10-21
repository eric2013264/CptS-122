#ifndef TABLEENTRY_H_
#define TABLEENTRY_H_

class TableEntry {
public:
	TableEntry(int symbol, char type, char location);
	int getLocation() const;
	void setLocation(char location);
	int getSymbol() const;
	char getType() const;

private:
	int symbol; // Integer containing ASCII representation of a variable.
	char type; // 'C' for constant, 'L' for line number, 'V' for variable.
	int location; // Location in Simpletron memory, 00-99

};

#endif
