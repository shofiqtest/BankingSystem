#include "AccountOperation.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

long Create_Unique_ID() //Unique Integer ID. 
{
	return static_cast<long>(chrono::system_clock::to_time_t(chrono::system_clock::now()) / 4);
}

string currentDateTime() //ID created Date and Time // Ref: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c. 
{
	using namespace std::chrono;
	time_t now = system_clock::to_time_t(system_clock::now());
	char buffer[26];
	errno_t error = ctime_s(buffer, sizeof(buffer), &now);
	return buffer;
}

Account::Type Ask_Type_Of_Account() // Ask Type Account CUstomer/Enterprise. 
{
	const string Customer = "customer";
	const string Enterprise = "enterprise";

	Account::Type inputType = Account::INVALID;
	while (inputType == Account::INVALID)
	{
		cout << "----------------- Ask_Type_Of_Account -----------------";
		// Suggestion: Make separate function which prints instructions.
		string type;
		cout << "\nEnter Type of The account"
			<< "\nEnter " << Customer << " for Customer Account"
			<< "\nEnter " << Enterprise << " for Enterprise Account"
			<< "\nEnter Your Account Type: ";
		cin >> type;

		transform(type.begin(), type.end(), type.begin(), ::tolower);

		if (type == Customer) {
			inputType = Account::CUSTOMER;
		}
		else if (type == Enterprise) {
			inputType = Account::ENTERPRISE;
		}
		else {
			cout << "\nInvalid Type\n";
		}
	}

	return inputType;
}



Account newAccount; // Created Account 
void Create_Account(Account::Type type)

{
	cout << "\n----------------- Create_Account -----------------";

	string Full_Name = "", y_tunnus = "", Company_Name = "";

	if (type == Account::CUSTOMER)
	{
		string First_Name, Last_Name;
		cout << "\nEnter First_Name: ";
		cin >> First_Name;
		cout << "\nEnter Last_Name: ";
		cin >> Last_Name;
		Full_Name = First_Name + " " + Last_Name;
	}

	else if (type == Account::ENTERPRISE)

	{
		cout << "\nEnter Y-Tunnus: ";
		cin >> y_tunnus;
		cout << "\nEnter Company Name: ";
		cin >> Company_Name;
	}

	if (type == Account::CUSTOMER || type == Account::ENTERPRISE)

	{

		cout << "\nAccount created successfully!";

		newAccount.accountID = Create_Unique_ID();
		newAccount.balance = 0;
		newAccount.type = type;
		newAccount.created = currentDateTime();

		if (type == Account::CUSTOMER)
		{
			newAccount.name = Full_Name;
		}
		else
		{
			newAccount.name = Company_Name;
			newAccount.y_tunnus = y_tunnus;
		}
	}
	else
	{
		cout << "\nInvalied user input!";
	}

	cout << "\n----------------- Create_Account -----------------";
}



void getAccountDetails(Account account) // Get Account Deatils. 

{
	cout << "\nAccount ID: " << account.accountID;
	cout << "\nAccount Type: " << (account.type == Account::CUSTOMER ? "Customer" : "Enterprise");  // boolCondition ? firstOption : secondOption; Ternary operator
	cout << "\nAccount Holder: " << account.name;
	cout << "\nAccount Created: " << account.created;
	cout << "\nAccount Balance: " << account.balance;

	if (account.type == Account::ENTERPRISE)
		cout << "\nY-Tunnus: " << account.y_tunnus;
}


void add_or_remove(int choice) // Add and Decrease Balance

{
	string customer_choice;

	if (choice == 1)
		customer_choice = "Deposit";
	else
		customer_choice = "Withdraw";

	cout << "Enter " << customer_choice << " Amount: ";
	float amount;
	cin >> amount;

	if (choice == 1 && amount > 0)
		newAccount.balance += amount;

	else if (choice == 2)

		if (newAccount.balance >= amount)
			newAccount.balance -= amount;

		else
			cout << "Invalid Request";

}


void ask_customer_choice() // Account Transiction Choice

{
	cout << "\nEnter 1 for Deposit Balance";
	cout << "\nEnter 2 for Withdraw Balance";
	cout << "\nEnter 3 for View Details";
	cout << "\nEnter 4 for Exit";
	cout << "\nEnter Your Choice: ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
	case 2:
		add_or_remove(choice);
		break;
	case 3:
		getAccountDetails(newAccount);
		break;
	case 4:
		cout << "Thanks for Choosing";
		return;

	default:
		cout << "invalid choice ";
		break;

	} ask_customer_choice();

}
