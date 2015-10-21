#include "Header.h"

void cipher::setText() {
	bool run = true;
	int spot = 0;
	std::cin.clear();
	std::cin.ignore(100000, '\n');
	std::cout << ">>> ENTER TEXT (CAPS) >>> ";
	std::getline(std::cin, _text);
	while (run == true) { 
		while (_text[spot] != '\0') {
			if (((int)_text[spot] < (int)'A' || (int)_text[spot] > (int)'Z') && _text[spot] != ' ') {
				std::cout << ">>> (!)" << std::endl;
				std::cout << ">>> ENTER TEXT (CAPS) >>> ";
				std::getline(std::cin, _text);
			}
			else {
				spot++;
			}
		}
		if (_text[spot] == '\0') {
			run = false;
		}
	}	
}

void cipher::displayEncryptedText() {
	std::cout << ">>> ENCRYPTED TEXT >>> " <<_encryptedText << std::endl;
}

void cipher::displayDecryptedText() {
	std::cout << ">>> DECRYPTED TEXT >>> " <<_decryptedText << std::endl;
}