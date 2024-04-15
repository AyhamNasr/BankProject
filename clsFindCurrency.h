#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindCurrency : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

public:


	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nFind By : [1] Code or [2] Country ? ";
		short Choise = clsInputValidate::ReadIntNumberBetween(1, 2, "Enter Number Between [1 _ 2]");

		if (Choise == 1)
		{
			cout << "\nPlease Enter Currency Code ? ";
			string Code = clsInputValidate::ReadString();

			clsCurrency Currency1 = clsCurrency::FindByCode(Code);

			if (Currency1.IsEmpty())
				cout << "\nCurrency Not Found :( \n";
			else
			{
				cout << "\nCurrency Found :) \n";
				_PrintCurrency(Currency1);
			}
		}
		else
		{
			cout << "\nPlease Enter Currency Country ? ";
			string Country = clsInputValidate::ReadString();

			clsCurrency Currency1 = clsCurrency::FindByCountry(Country);
			if (Currency1.IsEmpty())
				cout << "\nCurrency Not Found :( \n";
			else
			{
				cout << "\nCurrency Found :) \n";
				_PrintCurrency(Currency1);
			}

		}
	}

};

