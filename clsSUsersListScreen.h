#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsSUsersListScreen : protected clsScreen
{
private:

	static void _PrintUserRecordLine(clsUser Client)
	{
		cout << "| " << setw(15) << left << Client.GetUserName();
		cout << "| " << setw(25) << left << Client.FullName();
		cout << "| " << setw(15) << left << Client.Phone;
		cout << "| " << setw(15) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PassWord;
		cout << "| " << setw(10) << left << Client.Permissions << endl;
	}
public:

	static void ShowUserList()
	{
		vector<clsUser> vClients;
		vClients = clsUser::GetClientList();

		string Title = "\t  User List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") User(s).";


		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(10) << "PassWord";
		cout << "| " << left << setw(10) << "Permissions";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients avalible in the system !";
		}
		else
			for (clsUser& C : vClients)
			{
				_PrintUserRecordLine(C);
			}
	}

};

