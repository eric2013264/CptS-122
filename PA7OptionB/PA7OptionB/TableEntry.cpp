#include "TableEntry.h"

TableEntry::TableEntry(int symbol, char type, char location):
symbol(symbol),
type(type),
location(location)
{
}

int TableEntry::getLocation() const {
	return location;
}

void TableEntry::setLocation(char location) {
	this->location = location;
}

int TableEntry::getSymbol() const {
	return symbol;
}

char TableEntry::getType() const {
	return type;
}
