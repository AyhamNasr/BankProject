#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"


using namespace std;

class clsListCurrenceisScreen : protected clsScreen
{

private:

	static void _PrintClientRecordLine(clsCurrency Currency)
	{
		cout << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(13) << left << Currency.CurrrencyCode();
		cout << "| " << setw(30) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate() << endl;
	}

public:

	static void ShowCurrenceisList()
	{
		vector<clsCurrency> vCurrency;
		vCurrency = clsCurrency::vLodeAllCurrencyData();

		string Title = "\t  Currency List Screen";
		string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Curence(s).";




		cout << "\n\t\t\t\t\tCurrencies List (" << vCurrency.size() << ") Currency(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Currency Code";
		cout << "| " << left << setw(30) << "Currency Name";
		cout << "| " << left << setw(10) << "Rate By Dolar";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		for (clsCurrency& C : vCurrency)
		{
			_PrintClientRecordLine(C);
		}

	}
};

