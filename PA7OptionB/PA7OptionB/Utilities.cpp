#include "Utilities.h"

using namespace std;

namespace util {

bool isStringNumber(string str) {
	for (int i = 0; i < str.size(); i++) {
		char c = str.at(i);
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}

}
