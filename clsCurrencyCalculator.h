#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyCalculator : protected clsScreen
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

	static void ShowCurrencyCalculator()
	{
		char Choise = 'n';

		do
		{
			if (Choise == 'y' || Choise == 'Y')
			{
				system("cls");
			}

			clsScreen::_DrawScreenHeader("\tCurrency Calculator Screen");

			cout << "\nPlease Enter Currency1 Code ? ";
			string Code = clsInputValidate::ReadString();

			while (!clsCurrency::IsCurrencyExistCode(Code))
			{
				cout << "\nCurrency is not found, choose another one: ";
				Code = clsInputValidate::ReadString();
			}

			clsCurrency Currency1 = clsCurrency::FindByCode(Code);

			cout << "\nPlease Enter Currency2 Code ? ";
			Code = clsInputValidate::ReadString();

			while (!clsCurrency::IsCurrencyExistCode(Code))
			{
				cout << "\nCurrency is not found, choose another one: ";
				Code = clsInputValidate::ReadString();
			}

			clsCurrency Currency2 = clsCurrency::FindByCode(Code);

			cout << "\nEnter Amount to Exchange : ";
			float Amount = clsInputValidate::ReadDblNumber("");

			cout << "\nConvert From\n";
			_PrintCurrency(Currency1);

			float FinalResult = 0;

			FinalResult = Currency1.ExchangeFromXToDolar(Amount);

			cout << Amount << " " << Currency1.CurrrencyCode() << " = " << FinalResult << " USD \n";
			cout << "\nConvrting from USD to\n";


			_PrintCurrency(Currency2);

			FinalResult = Currency2.ExchangeFromDolarToX(FinalResult);

			cout << Amount << " " << Currency1.CurrrencyCode() << " = " << FinalResult << " " << Currency2.CurrrencyCode() << endl;


			cout << "\nDo You want to perform another calculation ? (Y/N) ? ";
			cin >> Choise;
		} while (Choise == 'y' || Choise == 'Y');

	}

};

