#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		clsScreen::_DrawScreenHeader("\t Withdraw Screen");

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


		cout << "\nPlease Enter Amount You Wont Withdraw it ?\n";
		Amount = clsInputValidate::ReadDblNumber("Rong Enterd , try Again");

		while (!Client.Withdraw(Amount))
		{
			cout << "\nThe Amout you Wont Withdraw it More than your Balance , tray another amount\n";
			Amount = clsInputValidate::ReadDblNumber("");
		}

		cout << "\nAre You Sure you wont Withdraw this Amount (" << Amount << ") (Y/N) ? \n";

		char Answer = 'n';

		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{


			cout << "\nWithdraw Operation  Successfully. \n";
			cout << "\nThe New Balance is = " << Client.AccountBalance << endl;

		}
		else
		{
			cout << "\nThe Operation Cancelled \n";
		}

	}
};

