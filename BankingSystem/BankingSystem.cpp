// BankingSystem.cpp : Defines the entry point for the application.
//

#include "AccountOperation.h"


int main()
{
	Account::Type type = Ask_Type_Of_Account();
	Create_Account(type);
	ask_customer_choice();
}