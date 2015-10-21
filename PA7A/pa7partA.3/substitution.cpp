#include "Header.h"

void substitution::setKey() {
	bool run = true, pass1 = true, pass2 = true;
	int spot = 0, spot2 = 0, spot3 = 0, spot4 = 0;
	std::string test = "__________________________";
	while (run == true) { 
		std::cout << ">>> ENTER ENCRYPTION KEY (26 DIFFERENT LETTERS) >>> ";
		std::cin >> _key;	
		while (_key[spot2] != '\0') {
			if (((int)_key[spot2] < (int)'A' || (int)_key[spot2] > (int)'Z')) { //must all be capital
				pass1 = false;
			}
			spot++;
			spot2++;
		}
		while (_key[spot3] != '\0' && pass1 == true) { //must only be used once
			test[((int)_key[spot3])-(int)'A'] = _key[spot3];
			spot3++;
		}
		while (test[spot4+1] != '\0' && pass1 == true) {
			if (test[spot4] >= test[spot4+1] || test[spot4] == '_' ||test[spot4+1] == '_') {
				pass2 = false;
			}
			spot4++;
		}
		if (pass2 == false || pass1 == false || spot3 != 26) {
			pass2 = true;
			pass1 = true;
			spot = 0;
			spot2 = 0;
			spot3 = 0;
			spot4 = 0;
			test = "__________________________";
			_key = "";
			std::cout << ">>> (!)" << std::endl;
		}
		else {
			run = false;
		}
	}
	std::cout << ">>> ENCRYPTION KEY YOU ENTERED >>> " << _key << std::endl;
}

void substitution::setDecryptionKey() {
	bool run = true, pass1 = true, pass2 = true;
	int spot = 0, spot2 = 0, spot3 = 0, spot4 = 0;
	std::string test = "__________________________";
	while (run == true) { 
		std::cout << ">>> ENTER DECRYPTION KEY (26 DIFFERENT LETTERS) >>> ";
		std::cin >> _decryptionKey;	
		while (_decryptionKey[spot2] != '\0') {
			if (((int)_decryptionKey[spot2] < (int)'A' || (int)_decryptionKey[spot2] > (int)'Z')) { //must all be capital
				pass1 = false;
			}
			spot++;
			spot2++;
		}
		while (_decryptionKey[spot3] != '\0' && pass1 == true) { //must only be used once
			test[((int)_decryptionKey[spot3])-(int)'A'] = _decryptionKey[spot3];
			spot3++;
		}
		while (test[spot4+1] != '\0' && pass1 == true) {
			if (test[spot4] >= test[spot4+1] || test[spot4] == '_' ||test[spot4+1] == '_') {
				pass2 = false;
			}
			spot4++;
		}
		if (pass2 == false || pass1 == false || spot3 != 26) {
			pass2 = true;
			pass1 = true;
			spot = 0;
			spot2 = 0;
			spot3 = 0;
			spot4 = 0;
			test = "__________________________";
			_decryptionKey = "";
			std::cout << ">>> (!)" << std::endl;
		}
		else {
			run = false;
		}
	}
	std::cout << ">>> ENCRYPTION KEY YOU ENTERED >>> " << _decryptionKey << std::endl;
}
	
void substitution::encryptText() {
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count = 0;
	_encryptedText = "";
	while (_text[count] != '\0') {
		if(_text[count] != ' ') {
			_encryptedText += _key[((int)alphabet[((int)_text[count]-(int)'A')]-(int)'A')];
		}
		else {
			_encryptedText += ' ';
		}
		count++;
	}
}

void substitution::decryptText() {
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count = 0, count2 = 0;
	_decryptedText = "";
	while (_encryptedText[count] != '\0') {
		if (_encryptedText[count] != ' ') {
			while((char)_decryptionKey[count2] != (char)_encryptedText[count]) {
				count2++;
			}
			_decryptedText += (char)alphabet[count2];
			count2 = 0;
		}
		else {
			_decryptedText += ' ';
		}
		count++;
	}
}


void substitution::decode() {
	int count = 0, spot = 0, spot2 = 0, spot3 = 0, spot4 = 0, spot5 = 0, spot6 = 0, spot7 = 0;
	double charcount[26] = {0}, smallest = 0.0;
	double charstats[26][26] = {{0}};
	double freqStandard[26] = {8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03, 5.92, 7.31, 0.10, 0.69, 3.98, 2.61, 6.95, 7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 2.88, 1.11, 2.09, 0.17, 2.11, 0.07}; 
	//frequencry numbers referenced from http://www.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html
	_decodedKey = "";
	while (_encryptedText[spot] != '\0') {
		if (_encryptedText[spot] != ' ') {
			charcount[((int)_encryptedText[spot]-(int)'A')]++;
			count++;
		}
		spot++;
	}
	while (spot2 < 26) {
		while (spot3 < 26) {
			charstats[spot2][spot3] = ((abs(((((charcount[spot2]/count*100)-(freqStandard[spot3])))/(((charcount[spot2]/count*100)+(freqStandard[spot3]))/2))))*100);
			spot3++;
		}
		spot3 = 0;
		spot2++;
	}
	std::cout << ">>> [PLEASE ELARGE CONSOLE WINDOW SIZE!]";
	std::cout << "\n>>> THE FOLLOWING SHOWS THE % DIFFERENCE WITH THE CHARACTER \nFREQUECNY IN THE ENCODED TEXT AND THE CHARACTER FREQUENCY IN REALITY\n HIGHER % MEANS LESS LIKELY TO BE THAT CHARACTER" << std::endl;
	std::cout << "	A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z" << std::endl;
	std::cout << "	___________________________________________________________________________________________________________________________________________________________________________________________________________________"<< std::endl;
	while (spot4 < 26) {
		std::cout << (char)(spot4 + (int)'A') << " -> | ";
		while (spot5 < 26) {
			std::cout.precision(3);
			std::cout << charstats[spot4][spot5] << "	";
			spot5++;
		} 
		spot5 = 0;
		std::cout << std::endl;
		spot4++;
	}
	while (spot5 < 26) {
		smallest = charstats[spot5][0];
		while (spot6 < 26) {
			if (smallest > charstats[spot5][spot6]) {
				smallest = charstats[spot5][spot6];
				spot7 = spot6;
			}
			spot6++;
		}
		_decodedKey += (char)(spot7+(int)'A');
		spot6 = 0;
		spot5++;
	}
	std::cout << ">>> SUGGESTED KEY FOR ALPHABET (BASED ON LOWEST FREQUENCY DIFFERENCE IN TABLE ABOVE >>>\n\n>>> ABCDEFGHIJKLMNOPQRSTUVWXYZ" << std::endl;
	std::cout << ">>> ||||||||||||||||||||||||||" << std::endl;
	std::cout << ">>> "<<_decodedKey <<" <- THESE ARE THE SUGGESTED REPLACEMENT CHARACTERS FOR ALPHABET\n\n\n\n\n" << std::endl;
}