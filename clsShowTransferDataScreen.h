#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"


using namespace std;

class clsShowTransferDataScreen : protected clsScreen
{
private:

	static void _PrintClientTransferRecordLine(clsBankClient::stTransferData TransferData)
	{
		cout << "| " << setw(25) << left << TransferData.DateAndTime;
		cout << "| " << setw(15) << left << TransferData.AccountNum1;
		cout << "| " << setw(15) << left << TransferData.AccountNum2;
		cout << "| " << setw(10) << left << TransferData.Amount;
		cout << "| " << setw(10) << left << TransferData.AccountBalan1;
		cout << "| " << setw(10) << left << TransferData.AccountBalan2;
		cout << "| " << setw(10) << left << TransferData.UserName << endl;
	}

public:

	static void ShowTransferLogData()
	{
		vector<clsBankClient::stTransferData> vTransData;
		vTransData = clsBankClient::LodingTranferLogDataFromFile();

		string Title = "\t  Transfer Data Screen";
		string SubTitle = "\t    (" + to_string(vTransData.size()) + ") Transfer(s).";


		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tTransfer Data List (" << vTransData.size() << ") Transfer(s).";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << "| " << left << setw(25) << "Time And Date";
		cout << "| " << left << setw(15) << "S.AccountN";
		cout << "| " << left << setw(15) << "D.AccountN";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(10) << "UserName";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vTransData.size() == 0)
		{
			cout << "\t\t\tNo Transfers avalible in the system !";
		}
		else
			for (clsBankClient::stTransferData& C : vTransData)
			{
				_PrintClientTransferRecordLine(C);
			}

	}
};

