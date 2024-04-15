#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsShowAllClientScreen.h"
#include"clsAddClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"
#include"clsLoginDataScreen.h"
#include"clsCurrencyMenueScreen.h"


using namespace std;

class clsMainscreen : protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginData = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10 ?");

		return Choice;
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientSecreen()
	{
		//cout << "\nClient List Screen Will be here...\n";

		clsShowAllClientScreen::ShowClientList();
	}

	static void _ShowAddNewClientSecreen()
	{
		/*cout << "\nAdd New Client Secreen Will be here...\n";*/

		clsAddClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be here...\n";

		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";

		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::FindClient();
	}

	static void _ShowTransactionsMenue()
	{
		//cout << "\nTransactions Menue Will be here...\n";

		clsTransactionsScreen::showTransactionMenu();
	}

	static void _ShowManageUsersMenue()
	{
		/*cout << "\nUsers Menue Will be here...\n";*/

		clsManageUsersScreen::ShowManageUserScreen();

	}

	static void _ShowLoginData()
	{
		clsLoginDataScreen::ShowLoginData();
	}

	static void _ShowCurrencyMenue()
	{
		clsCurrencyMenueScreen::ShowCurrencyMenue();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");

	}
	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case clsMainscreen::eListClients:
			system("cls");
			_ShowAllClientSecreen();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientSecreen();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eManageUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eLoginData:
			system("cls");
			_ShowLoginData();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eCurrencyExchange:
			system("cls");
			_ShowCurrencyMenue();
			_GoBackToMainMenue();
			break;
		case clsMainscreen::eExit:
			system("cls");
			_Logout();
			break;

		}
	}
public:
	static void ShowMainMenue()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("\t\tMain Menue");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Show Login Data.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenuOption());
	}

};

