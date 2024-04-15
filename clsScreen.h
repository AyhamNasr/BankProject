#pragma once
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser : " << CurrentUser.GetUserName() << endl;

        cout << "\t\t\t\t\tDate : " << clsDate::GetSystemDateTimeString();
        cout << endl;

    }

    static bool _CheckAccessRights(clsUser::enPermission Permission)
    {
        if (!CurrentUser.AccessPermission(Permission))
        {
            _DrawScreenHeader("  Access Denied! Contact Your Admin ");
            return false;
        }
        else
        {
            return true;
        }

    }

};

