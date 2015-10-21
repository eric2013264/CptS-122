///////////////////////////////////////////////////////////////////////////////
/// \file         BankManager.cpp
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  10/21/14 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#include "BankManager.h"

///////////////////////////////////////////////////////////////////////
/// BankManager ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

BankManager::BankManager ()
{
	mAccountsPtr = new Account[1024];
	mAccountsAvailablePtr = new bool[1024];
	
	for (int counter = 0; counter < 1024; counter++)
	{
		mAccountsAvailablePtr[counter] = true;
	}

	mNumberAccounts = 1024;
}

///////////////////////////////////////////////////////////////////////
/// BankManager ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

BankManager::BankManager (int maxNumberAccounts)
{
	mAccountsPtr = new Account[maxNumberAccounts];
	mAccountsAvailablePtr = new bool[maxNumberAccounts];

	for (int counter = 0; counter < maxNumberAccounts; counter++)
	{
		mAccountsAvailablePtr[counter] = true;
	}

	mNumberAccounts = maxNumberAccounts;
}

///////////////////////////////////////////////////////////////////////
/// ~BankManager ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

BankManager::~BankManager ()
{
	delete [] mAccountsPtr;
	delete [] mAccountsAvailablePtr;
}

///////////////////////////////////////////////////////////////////////
/// getAccountPtr ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

Account * BankManager::getAccountsPtr () const
{
	return mAccountsPtr;
}

///////////////////////////////////////////////////////////////////////
/// getAccountsAvailablePtr ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

bool * BankManager::getAccountsAvailablePtr () const
{
	return mAccountsAvailablePtr;
}

///////////////////////////////////////////////////////////////////////
/// getNumberAccounts ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

int BankManager::getNumberAccounts () const
{
	return mNumberAccounts;
}

///////////////////////////////////////////////////////////////////////
/// setAccountsPtr ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void BankManager::setAccountsPtr (Account *newAccountsPtr)
{
	mAccountsPtr = newAccountsPtr;
}

///////////////////////////////////////////////////////////////////////
/// setAccountsAvailablePtr ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void BankManager::setAccountsAvailablePtr (bool *newAccountsAvailablePtr)
{
	mAccountsAvailablePtr = newAccountsAvailablePtr;
}

///////////////////////////////////////////////////////////////////////
/// setNumberAccounts ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void BankManager::setNumberAccounts (int newNumberAccounts)
{
	mNumberAccounts = newNumberAccounts;
}

///////////////////////////////////////////////////////////////////////
/// displayMenu ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void BankManager::displayMenu ()
{
	cout << "1. Create account" << endl;
	cout << "2. Delete account" << endl;
	cout << "3. Update account" << endl;
	cout << "4. Display account" << endl;
	cout << "5. Exit" << endl;
}

///////////////////////////////////////////////////////////////////////
/// getMenuOption ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

int BankManager::getMenuOption () const
{
	int option = 0;

	cin >> option;

	system ("cls");

	return option;
}

///////////////////////////////////////////////////////////////////////
/// createAccount ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

bool BankManager::createAccount ()
{
	int accountNumber = 0;
	double balance = 0.0;
	char cStringName[100];
	string name = "", dateCreated = "";
	bool success = true;

	cout << "Enter account number: ";
	cin >> accountNumber;

	cout << "Enter name: ";
	cin.clear ();
	cin.sync ();
	cin.getline (cStringName, 100);
	name = cStringName;

	cout << "Enter balance: ";
	cin >> balance;

	cout << "Enter date: ";
	cin >> dateCreated;

	int counter = 0;
	while ((mAccountsAvailablePtr[counter] != true) && (counter < mNumberAccounts)) 
	{
		// search for avialable account space in the array
		counter++;
	}

	if (mNumberAccounts <= counter)
	{
		cout << "WARNING: Could not create account!" << endl;
		success = false;
	}
	else
	{
		mAccountsPtr[counter].setAccountNumber (accountNumber);
		mAccountsPtr[counter].setName (name);
		mAccountsPtr[counter].setBalance (balance);
		mAccountsPtr[counter].setDateCreated (dateCreated);

		mAccountsAvailablePtr[counter] = false;
	}

	return success;
}

///////////////////////////////////////////////////////////////////////
/// deleteAccount ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

bool BankManager::deleteAccount ()
{
	bool success = false;
	int accountNumber = 0;
	int counter = 0;

	counter = findAccount ();

	if ((counter < mNumberAccounts) && (mAccountsAvailablePtr[counter] == false)) // we found the account, so delete it
	{
		success = true;
		mAccountsAvailablePtr[counter] = true;
		cout << "Account deleted!" << endl;
	}

	return success;
}

///////////////////////////////////////////////////////////////////////
/// updateAccount ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

bool BankManager::updateAccount ()
{
	bool success = false;
	string name = "", dateCreated = "";
	double balance = 0.0, deposit = 0.0;
	int accountNumber = 0, counter = 0, option = 0;

	counter = findAccount ();

	if ((counter < mNumberAccounts) && (mAccountsAvailablePtr[counter] == false)) // we found the account, so delete it
	{
		success = true;

		cout << "1. Update Name" << endl;
		cout << "2. Withdraw Money" << endl;
		cout << "3. Deposit Money" << endl;

		cin >> option;

		switch (option)
		{
			case 1: cout << "Enter name: ";
					cin >> name;
					mAccountsPtr[counter].setName (name);
				    break;
			case 2: cout << "Enter amount to withdraw: ";
					cin >> balance;
					mAccountsPtr[counter].debit (balance);
				    break;
			case 3: cout << "Enter amount to deposit: ";
					cin >> deposit;
					mAccountsPtr[counter].credit (deposit);
				    break;
			default: cout << "ERROR: Invalid option!" << endl;
				     break;
		}
	}

	return success;
}

///////////////////////////////////////////////////////////////////////
/// displayAccount ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void BankManager::displayAccount () const
{
	int counter = 0;

	counter = findAccount ();

	if ((counter < mNumberAccounts) && (mAccountsAvailablePtr[counter] == false)) // we found the account, so delete it
	{
		mAccountsPtr[counter].printBalance ();
	}
	else
	{
		cout << "WARNING: Account does not exist!" << endl;
	}
}

///////////////////////////////////////////////////////////////////////
/// findAccount ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

int BankManager::findAccount () const // find the index for the account
{
	int accountNumber = 0;

	cout << "Enter account number: ";
	cin >> accountNumber;

	int counter = 0;
	for (counter = 0; ((counter < mNumberAccounts) && (mAccountsPtr[counter].getAccountNumber () != accountNumber)); counter++)
	{
		// The header of the for () takes care of all logic
	}

	return counter;
}

///////////////////////////////////////////////////////////////////////
/// runBankApplication ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void BankManager::runBankApplication ()
{
	int option = 0;
	bool status = true, success = true;;

	cout << "*** Welcome to AO's user friendly banking system ***" << endl << endl;

	do
	{
		displayMenu ();
		option = getMenuOption ();

		switch (option)
		{
			case 1: success = createAccount ();
					if (success == false)
					{
						cout << "WARNING: Could not create account!" << endl;
					}
				    break;
			case 2: success = deleteAccount ();
					if (success == false)
					{
						cout << "WARNING: Could not delete account!" << endl;
					}

				    break;
			case 3: success = updateAccount ();
					if (success == false)
					{
						cout << "WARNING: Could not update account!" << endl;
					}

				    break;
			case 4: displayAccount ();
				    break;
			case 5: status = false;
				    break;
			default: cout << "ERROR: Invalid choice!" << endl;
				     break;
		}
	} while (status != false);
}