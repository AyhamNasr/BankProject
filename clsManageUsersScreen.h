#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsSUsersListScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsUpdateUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersOperation {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5
		, eMainMenue = 6
	};

	static short _ReadOption()
	{
		short Option = 0;

		cout << setw(36) << left << "" << "Choose What you want to do ? [1 to 6] ? ";

		Option = clsInputValidate::ReadIntNumberBetween(1, 6, "Please Enter Number Beteen [1 to 4]");

		return Option;

	}

	static void _GoBackToManageUserMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Menue...\n";

		system("pause>0");

		ShowManageUserScreen();
	}

	static void _ShowListUserScreen()
	{
		//cout << "\t\tList User Screen Will be here \n";

		clsSUsersListScreen::ShowUserList();
	}

	static void _ShowAddNewUserScreen()
	{
		/*cout << "\t\tAdd New User Screen Will be here \n";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		/*cout << "\t\tDelete User Screen Will be here \n";*/

		clsDeleteUserScreen::ShowDeleteScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		/*cout << "\t\tUpdate User Screen Will be here \n";*/

		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		/*cout << "\t\tFind User Screen Will be here \n";*/

		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersOption(enManageUsersOperation Option)
	{
		switch (Option)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsersScreen::eMainMenue:
		{

		}

		}
	}

public:

	static void ShowManageUserScreen()
	{
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermission::pManageUsers))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Manage Users Screen ");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersOption((enManageUsersOperation)_ReadOption());
	}
};

