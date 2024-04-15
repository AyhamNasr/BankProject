#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListCurrenceisScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyMenueScreen : protected clsScreen
{
private:

	enum enCurrencyOption {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdataRata = 3, eCurrencyCalculator = 4
		, eMainMenue = 5
	};

	static short _ReadOption()
	{
		short Choose;

		cout << setw(37) << left << "" << "\n\t\t\t\tChoose What Do You Want To Do ? [1 / 5] ? ";

		Choose = clsInputValidate::ReadIntNumberBetween(1, 5, "\nOut of range , enter Again");

		return Choose;
	}

	static  void _GoBackToCurrencyMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Menue...\n";

		system("pause>0");
		ShowCurrencyMenue();
	}

	static void _ShowCurrencyListScreen()
	{
		clsListCurrenceisScreen::ShowCurrenceisList();

	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\n Find Currency Screen\n";

		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\n Update Rate Screen\n";

		clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n Currency Calculator Screen\n";

		clsCurrencyCalculator::ShowCurrencyCalculator();
	}

	static void _PerformCurrencyMenueOption(enCurrencyOption Option)
	{
		switch (Option)
		{
		case clsCurrencyMenueScreen::eCurrenciesList:
			system("cls");
			_ShowCurrencyListScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyMenueScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyMenueScreen::eUpdataRata:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyMenueScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyMenueScreen::eMainMenue:
			break;

		}
	}

public:

	static void ShowCurrencyMenue()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show CUrrency List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenueOption((enCurrencyOption)_ReadOption());

	}
};

