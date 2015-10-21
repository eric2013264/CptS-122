///////////////////////////////////////////////////////////////////////////////
/// \file         Account.h
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  10/21/14 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Account
{
	public:
		Account (double initialBalance = 0.0, 
			     int newAccountNumber = 0,
				 string newName = "",
				 string newDateCreated = "");
		Account (Account &copyAccount); // shallow copy
		~Account ();

		Account & operator= (const Account &rhs);

		double getBalance () const;
		int getAccountNumber () const;
		string getName () const;
		string getDateCreated () const;

		void setBalance (double newBalance);
		void setAccountNumber (int newAccountNumber);
		void setName (string newName);
		void setDateCreated (string newDateCreated);

		double credit (double newAmount);
		double debit (double newAmount);
		void printBalance ();

	private:
		double mBalance;
		int mAccountNumber;
		string mName;
		string mDateCreated;
};

#endif