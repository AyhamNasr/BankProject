#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsClientBalances.h"
#include"clsTransferScreen.h"
#include"clsShowTransferDataScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionOptions {
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eShowTransferData = 5,
		eMainMenue = 6
	};

	static short _ReadOption()
	{
		short Option = 0;

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";

		Option = clsInputValidate::ReadIntNumberBetween(1, 6, "Please Enter Number Beteen [1 to 6]");

		return Option;
	}

	static void _GoBackToTrnsactionMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

		system("pause>0");
		showTransactionMenu();
	}

	static void _ShowDepositScreen()
	{
		//cout << setw(37) << left << "" << "\n\tDeposit Screen will be here ....\n";

		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		/*cout << setw(37) << left << "" << "\n\tWithdraw Screen Will Be Here...\n";*/

		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		/*cout << setw(37) << left << "" << "\n\tTotal Balances screen will be here...\n";*/

		clsClientBalances::ShowClientBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();


	}

	static void _ShowAllTransferDataScreen()
	{
		clsShowTransferDataScreen::ShowTransferLogData();
	}

	static void _ShowMainMenuScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		//clsMainscreen::ShowMainMenue();
	}

	static void _PerformTransactionOption(enTransactionOptions Option)
	{

		switch (Option)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTrnsactionMenu();
			break;
		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTrnsactionMenu();
			break;
		case clsTransactionsScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTrnsactionMenu();
			break;
		case clsTransactionsScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTrnsactionMenu();
			break;
		case clsTransactionsScreen::eShowTransferData:
			system("cls");
			_ShowAllTransferDataScreen();
			_GoBackToTrnsactionMenu();
			break;
		case clsTransactionsScreen::eMainMenue:
		{

		}

		}
	}

public:

	static void showTransactionMenu()
	{
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermission::pTransactions))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Transaction Screen ");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Show Transfer Data Screen.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionOption((enTransactionOptions)_ReadOption());
	}
};

