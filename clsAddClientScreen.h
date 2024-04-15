#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>

using namespace std;

class clsAddClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name ? ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name ? ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email ? ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone ? ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Pin Code ? ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Ballance ? ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber("Invalid , tray again");
	}

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

	static void AddNewClient()
	{

		if (!_CheckAccessRights(clsUser::enPermission::pAddNewClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Add New Client Screen ");

		string AccountNumber = "";

		cout << "\nPlease enter client Account Number you wont Add it : " << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe Client You Wont Add Is Exist , enter another account number ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClaint = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClaint);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClaint.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError Account is not saved because it's empty \n";
			break;
		case clsBankClient::svSucceeded:
		{
			cout << "\nThe Account Add successfully :-) \n";
			_Print(NewClaint);
			break;
		}
		case clsBankClient::svFaildAccountNumberExists:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
	}


};



