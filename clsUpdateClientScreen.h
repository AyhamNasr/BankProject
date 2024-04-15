#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;
class clsUpdateClientScreen : protected clsScreen
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

	static void UpdateClient()
	{
		if (!_CheckAccessRights(clsUser::enPermission::pUpdateClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";

		cout << "\nPlease enter client Account Number you wont update it : " << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "\nUpdate Client Info : " << endl;
		cout << "-----------------------\n";

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError Account is not saved because it's empty \n";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nThe Account updated successfully :-) \n";
			_Print(Client);
			break;

		}

	}
};

