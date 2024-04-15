#include <iostream>
#include<vector>
#include<cctype>
#include<fstream>
using namespace std;
#pragma warning(disable : 4996)
#include <cmath>
#include<string>
#include<stack>
#include<ctime>
#include<iomanip>
#include"clsUtility.h"
#include"clsInputValidate.h"
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"clsString.h"
#include"clsLoginScreen.h"
#include"clsCurrency.h"


int main()
{
	// use UserName : User1 and Password : 1234

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		};
	}



	system("pause>0");
	return 0;
}
