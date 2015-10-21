///////////////////////////////////////////////////////////////////////////////
/// \file         Main Program App (main.cpp)
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///               Limited error checking is provided.
///           
///       
/// REVISION HISTORY:
/// \date  10/21/14 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#include "BankManager.h"

int main (void)
{
	BankManager bankApp;

	bankApp.runBankApplication ();

	return 0;
}