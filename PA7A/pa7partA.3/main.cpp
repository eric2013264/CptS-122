#include "Header.h"

int main(void) {
	bool run = true, run2 = true;
	int option = 0, option2 = 0, option3 = 0, option4 = 0;
	ceasar test;
	substitution demo;
	std::cout << ">>> ENCRYPTION PROGRAM >>> " << std::endl;
	while (run == true) {
		std::cout << ">>> OPTIONS >>>  (1) SUBSTITUTION CIPHER (2) CEASAR CIPHER" << std::endl;
		std::cout << ">>> ";
		std::cin >> option;
		while (option != 1 && option != 2) {
			std::cout << ">>> (!)\n>>> OPTIONS >>>  (1) SUBSTITUTION CIPHER (2) CEASAR CIPHER" << std::endl;
			std::cout << ">>> ";
			std::cin.clear();
			std::cin.ignore(100000,'\n');
			std::cin >> option;
		}
		system("CLS");
		switch(option) {
		case(1):
			demo.setText();
			demo.setKey();
			demo.encryptText();
			demo.displayEncryptedText();
			std::cout << ">>> WOULD YOU LIKE TO DECRYPT THE CODE? >>> (1) YES (2) NO" << std::endl;
			std::cout << ">>> ";
			std::cin >> option2;
			while (option2 != 1 && option2 != 2) {
				std::cout << ">>> (!)\n>>> WOULD YOU LIKE TO DECRYPT THE CODE? >>> (1) YES (2) NO" << std::endl;
				std::cout << ">>> ";
				std::cin.clear();
				std::cin.ignore(100000,'\n');
				std::cin >> option2;
			}
			system("CLS");
			if (option2 == 1) {
				std::cout << ">>> HOW WOULD YOU LIKE TO DECRYPT? >>> (1) WITH DECRYPTION KEY (2) DATA ANALYSIS " << std::endl;
				std::cout << ">>> ";
				std::cin >> option3;
				while (option3 != 1 && option3 != 2) {
					std::cout << ">>> HOW WOULD YOU LIKE TO DECRYPT? >>> (1) WITH DECRYPTION KEY (2) DATA ANALYSIS " << std::endl;
					std::cout << ">>> ";
					std::cin.clear();
					std::cin.ignore(100000,'\n');
					std::cin >> option3;
				}
				system("CLS");
				switch(option3) {
				case(1):
					demo.setDecryptionKey();
					demo.decryptText();
					demo.displayDecryptedText();
					break;
				case(2):
					demo.decode();
					break;
				}
			}
			break;
			system("CLS");
		case(2):
			test.setText();
			test.setKey();
			test.encryptText();
			test.displayEncryptedText();
			std::cout << ">>> WOULD YOU LIKE TO DECRYPT THE CODE? >>> (1) YES (2) NO" << std::endl;
			std::cout << ">>> ";
			std::cin >> option2;
			while (option2 != 1 && option2 != 2) {
				std::cout << ">>> (!)\n>>> WOULD YOU LIKE TO DECRYPT THE CODE? >>> (1) YES (2) NO" << std::endl;
				std::cout << ">>> ";
				std::cin.clear();
				std::cin.ignore(100000,'\n');
				std::cin >> option2;
			}
			system("CLS");
			if (option2 == 1) {
				std::cout << ">>> HOW WOULD YOU LIKE TO DECRYPT? >>> (1) WITH DECRYPTION KEY (2) TRIAL & ERROR " << std::endl;
				std::cout << ">>> ";
				std::cin >> option3;
				while (option3 != 1 && option3 != 2) {
					std::cout << ">>> (!)\n>>> HOW WOULD YOU LIKE TO DECRYPT? >>> (1) WITH DECRYPTION KEY (2) TRIAL & ERROR " << std::endl;
					std::cout << ">>> ";
					std::cin.clear();
					std::cin.ignore(100000,'\n');
					std::cin >> option3;
				}
				system("CLS");
				switch(option3) {
				case(1):
					test.setDecryptionKey();
					test.decryptText();
					test.displayDecryptedText();
					break;
				case(2):
					while (run2 == true) {
						test.setDecryptionKey();
						test.decryptText();
						test.displayDecryptedText();
						std::cout << ">>> AGAIN? >>> (1) YES (2) NO" << std::endl;
						std::cin >> option4;
						while (option4 != 1 && option4 != 2) {
							std::cout << ">>> (!)\n>>> AGAIN? >>> (1) YES (2) NO" << std::endl;
							std::cout << ">>> ";
							std::cin.clear();
							std::cin.ignore(100000,'\n');
							std::cin >> option4;
						}
						system("CLS");
						if (option4 == 2) {
							run2 = false;
						}
					}
					break;
				}
			}
		}
		std::cout << ">>> RUN PROGRAM AGAIN? >>> (1) YES (2) NO" << std::endl;
		std::cin >> option4;
		system("CLS");
		while (option4 != 1 && option4 != 2) {
			std::cout << ">>> (!)\n>>> RUN PROGRAM AGAIN? >>> (1) YES (2) NO" << std::endl;
			std::cout << ">>> ";
			std::cin.clear();
			std::cin.ignore(100000,'\n');
			std::cin >> option4;
		}
		if (option4 == 2) {
			run = false;
		}
		else {
			option, option2, option3, option4 = 0;
			run, run2 = true;
		}
	}
	system("CLS");
	return 0; 
}