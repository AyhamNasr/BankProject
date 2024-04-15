#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;
class clsDeleteUserScreen : protected clsScreen
{
private:

	static void _PrintUserCard(clsUser User)
	{
		cout << "\n_____________________________\n";
		cout << "\t User Card                   ";
		cout << "\n_____________________________\n";
		cout << "\nUser Full Name     : " << User.FullName();
		cout << "\nUser Phone         : " << User.Phone;
		cout << "\nUser Email         : " << User.Email;
		cout << "\nUser UserName      : " << User.GetUserName();
		cout << "\nUser User PassWord : " << User.PassWord;
		cout << "\nUser Permission    : " << User.Permissions;

	}

public:

	static void ShowDeleteScreen()
	{
		clsScreen::_DrawScreenHeader("\t Delete User Screen");

		cout << "Enter User Name For User You Want Delete it ? \n";
		string UserName = "";

		UserName = clsInputValidate::ReadString();




		while (!clsUser::IsClientExist(UserName))
		{
			cout << "The User Name is Not Exist Please Enter it Again ? \n";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);


		_PrintUserCard(User1);

		cout << "\n\nAre You Sure You Wont Delete User ? (Y/N) ? \n";

		char Answer = 'n';

		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfully :-) \n";
				_PrintUserCard(User1);

			}
			else
			{
				cout << "\nThe User Not Deleted Tray Again \n";
			}
		}
	}
};

