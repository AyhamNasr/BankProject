#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>

class clsShowAllClientScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.FirstName + " " + Client.LastName;
		cout << "| " << setw(10) << left << Client.Phone;
		cout << "| " << setw(10) << left << Client.AccountBalance << endl;
	}

public:

	static void ShowClientList()
	{
		if (!_CheckAccessRights(clsUser::enPermission::pListClient))
		{
			return;
		}
		vector<clsBankClient> vClients;
		vClients = clsBankClient::GetClientsList();

		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";


		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients avalible in the system !";
		}
		else
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
			}
	}
};

