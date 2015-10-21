///////////////////////////////////////////////////////////////////////////////
/// \file         Account.cpp
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  10/21/14 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#include "Account.h"

///////////////////////////////////////////////////////////////////////
/// Account ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

Account::Account (double initialBalance, int newAccountNumber,
				  string newName, string newDateCreated)
{
	if (initialBalance < 0.0)
	{
		mBalance = 0.0;
	}
	else
	{
		mBalance = initialBalance;
	}

	mAccountNumber = newAccountNumber;
	mName = newName;
	mDateCreated = newDateCreated;
}

///////////////////////////////////////////////////////////////////////
/// Account (Account &)
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

Account::Account (Account &copyAccount) // shallow copy
{
	mBalance = copyAccount.getBalance ();
	mAccountNumber = copyAccount.getAccountNumber ();
	mName = copyAccount.getName ();
	mDateCreated = copyAccount.getName ();
}

///////////////////////////////////////////////////////////////////////
/// ~Account ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

Account::~Account ()
{
	// Accounts are not created using dynamic memory.
	// This method does nothing.
}

///////////////////////////////////////////////////////////////////////
/// Assignment operator
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

Account & Account::operator= (const Account &rhs)
{
	if (this != &rhs)
	{
		mBalance = rhs.getBalance ();
		mAccountNumber = rhs.getAccountNumber ();
		mName = rhs.getName ();
		mDateCreated = rhs.getName ();
	}

	return *this;
}

///////////////////////////////////////////////////////////////////////
/// getBalance ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

double Account::getBalance () const
{
	return mBalance;
}

///////////////////////////////////////////////////////////////////////
/// getAccountNumber ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

int Account::getAccountNumber () const
{
	return mAccountNumber;
}

///////////////////////////////////////////////////////////////////////
/// getName ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

string Account::getName () const
{
	return mName;
}

///////////////////////////////////////////////////////////////////////
/// getDateCreated ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

string Account::getDateCreated () const
{
	return mDateCreated;
}

///////////////////////////////////////////////////////////////////////
/// setBalance ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void Account::setBalance (double newBalance)
{
	mBalance = newBalance;
}

///////////////////////////////////////////////////////////////////////
/// setAccountNumber ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void Account::setAccountNumber (int newAccountNumber)
{
	mAccountNumber = newAccountNumber;
}

///////////////////////////////////////////////////////////////////////
/// setName ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void Account::setName (string newName)
{
	mName = newName;
}

///////////////////////////////////////////////////////////////////////
/// setDateCreated ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void Account::setDateCreated (string newDateCreated)
{
	mDateCreated = newDateCreated;
}

///////////////////////////////////////////////////////////////////////
/// credit ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

double Account::credit (double newAmount)
{
	mBalance += newAmount;
	return mBalance;
}

///////////////////////////////////////////////////////////////////////
/// debit ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

double Account::debit (double newAmount)
{
	if (newAmount > mBalance)
	{
		cout << "WARNING: Can't withdraw " << newAmount << " exceeds your funds!" << endl;
	}
	else
	{
		mBalance -= newAmount;
	}

	return mBalance;
}

///////////////////////////////////////////////////////////////////////
/// printBalance ()
/// \pre    
/// \post   
/// \param  (repeat for every parameter)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void Account::printBalance ()
{
	cout << "A#: " << mAccountNumber << endl;
	cout << "Name: " << mName << endl;
	cout << "Current Balance: " << mBalance << endl;
	cout << "Date Created: " << mDateCreated << endl;
}