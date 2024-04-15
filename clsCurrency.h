#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include"clsString.h"

using namespace std;

class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	string _ConvertObjectToLine(clsCurrency Currency, string Sepretar = "#//#")
	{
		return Currency.Country() + Sepretar + Currency.CurrrencyCode() + Sepretar + Currency.CurrencyName() + Sepretar +
			to_string(Currency._Rate);
	}

	static clsCurrency _ConvertLineToObject(string Line, string Sepretar = "#//#")
	{
		vector<string> vCurrencyData = clsString::Split(Line, Sepretar);

		clsCurrency Currency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));

		return Currency;
	}

	static vector<clsCurrency> _vLodeCurrencyData()
	{
		vector<clsCurrency> vCurrency;


		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToObject(Line);

				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;
	}

	void _SaveDataToFile(vector<clsCurrency>vCurrency)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string line;
			for (clsCurrency& C : vCurrency)
			{
				line = _ConvertObjectToLine(C);
				MyFile << line << endl;
			}

			MyFile.close();

		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrUpdate;

		vCurrUpdate = _vLodeCurrencyData();

		for (clsCurrency& C : vCurrUpdate)
		{
			if (C.CurrrencyCode() == CurrrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveDataToFile(vCurrUpdate);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);

		vector<clsCurrency> vFindCurr = _vLodeCurrencyData();

		for (clsCurrency& C : vFindCurr)
		{
			if (C.CurrrencyCode() == Code)
			{
				return C;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		vector<clsCurrency> vFindCurr = _vLodeCurrencyData();

		for (clsCurrency& C : vFindCurr)
		{
			if (clsString::UpperAllString(C.Country()) == Country)
			{
				return C;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	bool IsEmpty()
	{
		if (this->_Mode == enMode::EmptyMode)
			return true;
		else
			return false;
	}

	static bool IsCurrencyExistCode(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);

		if (Currency.IsEmpty())
			return false;
		else
			return true;
	}

	static bool IsCurrencyExistCountry(string CurrencyCountry)
	{
		clsCurrency Currency = FindByCountry(CurrencyCountry);

		if (Currency.IsEmpty())
			return false;
		else
			return true;
	}

	static vector<clsCurrency> vLodeAllCurrencyData()
	{
		return _vLodeCurrencyData();
	}

	float ExchangeFromXToDolar(float Amount)
	{
		float FinalResult = 0;



		FinalResult = Amount / _Rate;


		return FinalResult;
	}

	float ExchangeFromDolarToX(float Amount)
	{
		float Result = 0;



		Result = Amount * _Rate;


		return Result;
	}


};

