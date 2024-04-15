#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"Global.h"
#include"clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;

		string UserName, Password;

		short Counter = 3;

		do
		{
			if (LoginFaild)
			{
				Counter--;

				cout << "\nInvalid Username or Password , Try Again ?\n";
				cout << "\nYou Have [" << Counter << "] Trials To Login \n";



				if (Counter == 0)
				{
					cout << "\nYou Are Locked After 3 Trials , Call Your Admin \n";
					return false;
				}

			}



			cout << "\nEnter User Name ?\n";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter PassWord ?\n";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.SaveLoginData();
		clsMainscreen::ShowMainMenue();

		return true;

	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("\t Login Screen ");

		if (!_Login())
		{
			return false;
		}

	}
};

