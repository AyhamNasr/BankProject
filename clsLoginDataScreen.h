#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"

using namespace std;

class clsLoginDataScreen : protected clsScreen
{
private:

	static void _PrintUserRecordLine(clsUser::stLoginData LoginData)
	{
		cout << "| " << setw(25) << left << LoginData.TimeAndDate;
		cout << "| " << setw(15) << left << LoginData.UserN;
		cout << "| " << setw(15) << left << LoginData.PassW;
		cout << "| " << setw(15) << left << LoginData.Permiss << endl;
	}

public:

	static void ShowLoginData()
	{

		if (!_CheckAccessRights(clsUser::enPermission::pLoginData))
		{
			return;
		}

		vector<clsUser::stLoginData> vClients;
		vClients = clsUser::LodeLoginDataFromFile();

		string Title = "\t  Login Data Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Login(s).";


		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Login(s).";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << "| " << left << setw(25) << "Time And Date";
		cout << "| " << left << setw(25) << "User Name";
		cout << "| " << left << setw(10) << "PassWord";
		cout << "| " << left << setw(10) << "Permissions";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Logins avalible in the system !";
		}
		else
			for (clsUser::stLoginData& C : vClients)
			{
				_PrintUserRecordLine(C);
			}
	}
};

