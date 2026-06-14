#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsString.h"
#include "clsUser.h"


using namespace std;


class clsLoginRegisterScreen:protected clsScreen
{

private:

   
    static void PrintLogin(clsUser::stLoginRegisterRecord LoginInfo) {

        cout << "\t\t\t " << setw(25) << left << LoginInfo.date;
        cout << "| " << setw(15) << left << LoginInfo.username;
        cout << "| " << setw(15) << left << LoginInfo.Password;
        cout << "| " << setw(15) << left << LoginInfo.permissions  << "\n";
    }

public :

	static void ShowLoginRegisterListScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister)){
            
            return;// this will exit the function and it will not continue
        }


        vector  <clsUser::stLoginRegisterRecord> Logins = clsUser::GetRecordRegisterList();

        string title, subtitle;

        title = "\tLogin register list screen";
        subtitle = "\t" + to_string(Logins.size()) + " Record(s)";

		_DrawScreenHeader(title,subtitle);


        cout << "\n\t\t\t--------------------------------------------------------------------------\n";
        cout<<"\t\t\t " << setw(25) << left << "Date/Time";
        cout<<"| " << setw(15) << left << "Username";
        cout<<"| " << setw(15) << left << "Password";
        cout<<"| " << setw(15) << left << "Permissions" << "\n";
        cout<<"\t\t\t--------------------------------------------------------------------------\n";

        for (clsUser::stLoginRegisterRecord& Record : Logins) {
            PrintLogin(Record);
        }
        cout << "\t\t\t--------------------------------------------------------------------------\n";

	}

};

