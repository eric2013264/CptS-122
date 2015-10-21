///////////////////////////////////////////////////////////////////////////////
/// \file         BankManager.h
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  10/21/14 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#ifndef BANK_MANAGER_H
#define BANK_MANAGER_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BankManager
{
	public:
		BankManager (); // default constructor
		BankManager (int numberAccounts); // constructor
		~BankManager (); // destructor

		// overloaded assignment operator
		BankManager & operator= (const BankManager &rhs);

		// getters / accessors
		Account * getAccountsPtr () const;
		bool * getAccountsAvailablePtr () const;
		int getNumberAccounts () const;

		// setters / mutators
		void setAccountsPtr (Account *newAccountsPtr);
		void setAccountsAvailablePtr (bool *newAccountsAvailablePtr);
		void setNumberAccounts (int newNumberAccounts);

		void displayMenu ();
		int getMenuOption () const;
		bool createAccount ();
		bool deleteAccount ();
		bool updateAccount ();
		void displayAccount () const;
		int findAccount () const;

		void runBankApplication ();

	private: // attributes
		Account *mAccountsPtr;
		bool *mAccountsAvailablePtr;
		int mNumberAccounts;
};

#endif