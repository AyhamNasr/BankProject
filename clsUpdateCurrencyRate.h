#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRate : protected clsScreen
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

	static void ShowUpdateCurrencyRateScreen()
	{
		clsScreen::_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "\nPlease Enter Currency Code ? ";
		string Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExistCode(Code))
		{
			cout << "\nCurrency is not found, choose another one: ";
			Code = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(Code);
		_PrintCurrency(Currency1);

		char Answer = 'n';

		cout << "\nAre You Sure You Want Update Rate Currency ? (Y/N) ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate \n _________________________ \n";
			cout << "\n\nEnter New Rate ? ";
			float Rate = clsInputValidate::ReadDblNumber("Invalid input , try again");

			Currency1.UpdateRate(Rate);

			cout << "\nCurrency Rate Updated Susseccfully :) \n";
			_PrintCurrency(Currency1);
		}
		else
			cout << "\nOpration Cancelled :( \n";

	}
};

