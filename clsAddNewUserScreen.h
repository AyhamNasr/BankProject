#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name ? ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name ? ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email ? ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone ? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password ? ";
		User.PassWord = clsInputValidate::ReadString();

		cout << "\nEnter Permissions ? ";
		User.Permissions = _ReadPermission();
	}

	static int _ReadPermission()
	{
		int Permission = 0;

		char Answer = 'n';

		cout << "\nAre you want Give All Access ? (Y/N) ? \n";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Permission = clsUser::enPermission::pAll;

		}
		else
		{
			cout << "\nAre You Want to Give Access For Show Client List ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pListClient;
			}

			cout << "\nAre You Want to Give Access For Add New Client ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pAddNewClient;
			}

			cout << "\nAre You Want to Give Access For Delete Client ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pDeleteClient;
			}

			cout << "\nAre You Want to Give Access For Update Client ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pUpdateClient;
			}

			cout << "\nAre You Want to Give Access For Find Client ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pFindClient;
			}

			cout << "\nAre You Want to Give Access For Transactions ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pTransactions;
			}

			cout << "\nAre You Want to Give Access For Manage User ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pManageUsers;
			}

			cout << "\nAre You Want to Give Access For Show Login Data ? (Y/N) ? \n";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Permission += clsUser::enPermission::pLoginData;
			}
		}

		return Permission;
	}

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

	static void ShowAddNewUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t Add New User Screen ");

		cout << "Enter User Name ? \n";
		string UserName = "";

		UserName = clsInputValidate::ReadString();

		while (clsUser::IsClientExist(UserName))
		{
			cout << "The User Name is Exist Please Enter it Again ? \n";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(User1);

		clsUser::enSaveResults SaveResult;

		SaveResult = User1.Save();

		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
			cout << "\nError User Not Saved Because it is Empty \n";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser Saved Successfully :-) \n";
			_PrintUserCard(User1);
			break;
		case clsUser::svFaildAccountNumberExists:
			cout << "\nUser Not Saved Because User Number Is Exist \n";
			break;
		default:
			break;
		}
	}

};

