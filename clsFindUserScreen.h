#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t Find User Screen");

		cout << "Enter User Name For User You Want Serch for it ? \n";

		string UserName = "";

		UserName = clsInputValidate::ReadString();




		while (!clsUser::IsClientExist(UserName))
		{
			cout << "The User Name is Not Exist Please Enter it Again ? \n";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);


		_PrintUserCard(User1);
	}

};

