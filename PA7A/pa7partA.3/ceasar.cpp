#include "Header.h"

void ceasar::setKey() {
	std::cout << ">>> ENTER ENCRYPTION KEY (-25 ... 25) >>> ";
	std::cin >> _key;
	while ((_key > 25 || _key < -25) || std::cin.fail()) { //abs == absolute value for +-25
		std::cout << ">>> (!)" << std::endl;
		std::cout << ">>> ENTER ENCRYPTION KEY (-25 ... 25) >>> ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> _key;
	}
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << ">>> ENCRYPTION KEY YOU ENTERED >>> " << _key << std::endl;
}

void ceasar::setDecryptionKey() {
	std::cout << ">>> ENTER DECRYPTION KEY (SAME USED TO ENCRPYT) >>> ";
	std::cin >> _decryptionKey;
	while ((_decryptionKey > 25 || _decryptionKey < -25) || std::cin.fail()) { //abs == absolute value for +-25
		std::cout << ">>> (!)" << std::endl;
		std::cout << ">>> ENTER DECRYPTION KEY (SAME USED TO ENCRPYT) >>> ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> _decryptionKey;
	}
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << ">>> DECRYPTION KEY YOU ENTERED >>> " << _decryptionKey << std::endl;
}

void ceasar::encryptText() {
	int spot = 0;
	_encryptedText = _text;
	while (_encryptedText[spot] != '\0') {
		if (_encryptedText[spot] != ' ') {
			if (_encryptedText[spot] + _key < 'A') {
				_encryptedText[spot] += (_key + 26);
			}
			else if (_encryptedText[spot] + _key > 'Z') {
				_encryptedText[spot] += (_key - 26);
			}
			else {
				_encryptedText[spot] += _key;
			}
			spot++;
		}
		else {
			spot++;
		}
	}
}

void ceasar::decryptText() {
	int spot = 0;
	_decryptedText = _encryptedText;
	while (_decryptedText[spot] != '\0') {
		if (_decryptedText[spot] != ' ') {
			if (_decryptedText[spot] - _decryptionKey < 'A') {
				_decryptedText[spot] -= (_decryptionKey - 26);
			}
			else if (_decryptedText[spot] - _decryptionKey > 'Z') {
				_decryptedText[spot] -= (_decryptionKey + 26);
			}
			else {
				_decryptedText[spot] -= _decryptionKey;
			}
			spot++;
		}
		else {
			spot++;
		}
	}
}