#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private:

	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FirstName + " " + Client.LastName;
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:

	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t Deposit Screen");

		string AccountNumber = "";

		cout << "\nPlease enter client Account Number  : " << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		double Amount = 0;

		cout << "\nPlease Enter Amount You Wont Deposit it ?\n";
		Amount = clsInputValidate::ReadDblNumber("Rong Enterd , try Again");

		cout << "\nAre You Sure you wont deposit this Amount (" << Amount << ") (Y/N) ? \n";

		char Answer = 'n';

		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client.Deposit(Amount);

			cout << "\nAmount Deposited Successfully. \n";
			cout << "\nThe New Balance is = " << Client.AccountBalance << endl;

		}
		else
		{
			cout << "\nThe Operation Cancelled \n";
		}

	}

};

