#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsBankClient.h"

using namespace std;

class clsUser : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };



	enMode _Mode;
	string _UserName;
	string _PassWord;
	int _Permissions;

	bool _MarkedForDelete = false;


	static clsUser _ConvertLineToUserObject(string Line, string Seprator = "#//#")
	{
		vector<string> vLineToClient;

		vLineToClient = clsString::Split(Line, Seprator);

		return clsUser(enMode::UpdateMode, vLineToClient[0], vLineToClient[1], vLineToClient[2], vLineToClient[3],
			vLineToClient[4], clsString::Decript(vLineToClient[5], 4), stoi(vLineToClient[6]));
	}

	static string _ConvertUserRecordToLine(clsUser _Clients, string Seperator = "#//#")
	{
		return _Clients.FirstName + Seperator + _Clients.LastName + Seperator + _Clients.Email + Seperator + _Clients.Phone
			+ Seperator + _Clients._UserName + Seperator + clsString::Encript((_Clients._PassWord), 4) + Seperator + to_string(_Clients._Permissions);
	}


	static  vector <clsUser> _LoadUsersDataFromFile()
	{

		vector <clsUser> vClients;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLineToUserObject(Line);

				vClients.push_back(Client);
			}
			MyFile.close();
		}

		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsUser> _vClients)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;

			for (clsUser& C : _vClients)
			{
				if (C._MarkedForDelete == false)
				{
					Line = _ConvertUserRecordToLine(C);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser> _vUsers;

		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C._UserName == _UserName)
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vUsers);
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserRecordToLine(*this));
	}

	struct stLoginData;

	static stLoginData _ConvertLineToStruct(string Line, string Spretar = "#//#")
	{
		stLoginData stData;
		vector<string> vData = clsString::Split(Line, Spretar);

		stData.UserN = vData[0];
		stData.TimeAndDate = vData[1];
		stData.PassW = clsString::Decript(vData[2], 4);
		stData.Permiss = vData[3];

		return stData;
	}

	string _ConvertLoginUserToLine()
	{
		return _UserName + "#//#" + clsDate::GetSystemDateTimeString() + "#//#" + clsString::Encript(_PassWord, 4) + "#//#" +
			to_string(_Permissions);
	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:



	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName
		, string PassWord, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permissions = Permissions;
	}

	enum enPermission {
		pAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8
		, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginData = 128
	};

	struct stLoginData
	{
		string UserN;
		string TimeAndDate;
		string PassW;
		string Permiss;
	};


	bool IsEmpty()
	{
		return this->_Mode == enMode::EmptyMode;
	}

	/*void SetUserName(string UserName)
	{
		_UserName = UserName;
	}*/

	string GetUserName()
	{
		return _UserName;
	}

	/*__declspec(property(get = GetUserName, put = SeUserName)) string UserName;*/

	void SetPassWord(string PassWord)
	{
		_PassWord = PassWord;
	}

	string GetPassWord()
	{
		return _PassWord;
	}

	__declspec(property(get = GetPassWord, put = SetPassWord)) string PassWord;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User._UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string PassWord)
	{
		clsUser User = Find(UserName);

		if (User._PassWord == PassWord)
		{
			return User;
		}

		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_UserName))

				return enSaveResults::svFaildAccountNumberExists;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}



		}



	}
	void SaveLoginData()
	{
		fstream MyFile;

		MyFile.open("LoginFile.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string Line;

			Line = _ConvertLoginUserToLine();
			MyFile << Line << endl;
			MyFile.close();
		}


	}

	bool Delete()
	{
		vector<clsUser>vDeleteUser;

		vDeleteUser = _LoadUsersDataFromFile();

		for (clsUser& C : vDeleteUser)
		{
			if (C._UserName == _UserName)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vDeleteUser);
		*this = _GetEmptyUserObject();

		return true;
	}

	static clsUser GetAddNewUserObject(string AccountNumber)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsUser> GetClientList()
	{

		return _LoadUsersDataFromFile();
	}

	static bool IsClientExist(string AccountNumber)
	{

		clsUser User1 = Find(AccountNumber);
		return (!User1.IsEmpty());
	}

	static vector<stLoginData> LodeLoginDataFromFile()
	{
		vector<stLoginData> vLoginData;

		fstream MyFile;

		MyFile.open("LoginFile.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stLoginData LogData;

			while (getline(MyFile, Line))
			{
				LogData = _ConvertLineToStruct(Line);
				vLoginData.push_back(LogData);
			}

			MyFile.close();
		}

		return vLoginData;


	}

	bool AccessPermission(enPermission Permission)
	{
		if (this->Permissions == enPermission::pAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;

		else
			return false;
	}
};

