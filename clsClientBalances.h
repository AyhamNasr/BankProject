#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtility.h"

using namespace std;

class clsClientBalances : protected clsScreen
{

private:

	static void PrintClientBalance(clsBankClient Client)
	{
		cout << "\t\t| " << setw(15) << left << Client.AccountNumber();
		cout << "\t\t| " << setw(40) << left << Client.FirstName;
		cout << "\t\t| " << setw(10) << left << Client.AccountBalance << endl;
	}
public:

	static void ShowClientBalances()
	{
		clsScreen::_DrawScreenHeader("\t Balances Screen ");


		vector<clsBankClient> vClients;
		vClients = clsBankClient::GetClientsList();

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t| " << left << setw(15) << "Accout Number";
		cout << "\t\t| " << left << setw(40) << "Client Name";
		cout << "\t\t| " << left << setw(12) << "Balance";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		for (clsBankClient& C : vClients)
		{
			PrintClientBalance(C);
		}

		double TotalBalances = clsBankClient::GetTotalBalances();

		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t\t\t\t\tThe Total Balances Of Clients is : " << TotalBalances << endl;
		cout << "\t\t\t\t\t(" << clsUtility::ConvertIntToString(TotalBalances) << ")" << endl;
	}
};

