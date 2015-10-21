#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

class cipher {
public:
	virtual void setKey()=0;
	virtual void setDecryptionKey()=0;
	virtual void encryptText()=0;
	virtual void decryptText()=0;

	void setText();
	void displayEncryptedText();
	void displayDecryptedText();

protected:
	std::string _text, _encryptedText, _decryptedText;
};

class ceasar: public cipher {
public:
	void setKey();
	void setDecryptionKey();
	void encryptText();
	void decryptText();
private:
	int _key, _decryptionKey;
};

class substitution: public cipher {
public:
	void setKey();
	void setDecryptionKey();
	void encryptText();
	void decryptText();
	void decode();
private:
	std::string _key, _decryptionKey, _decodedKey;
};

#endif