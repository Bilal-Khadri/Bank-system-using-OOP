#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        int trial = 3;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                trial--;
                if (trial == 0) {
                    cout << "\nYou are locked after 3 trials failed !\n";
                    return 0;
                }
                cout << "\nInvlaid Username/Password!\n";
               
                cout << "You have " << trial << " trials to login \n\n";
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
           
        } while (LoginFaild);


        clsMainScreen::ShowMainMenue();
        return 1;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen","",1);
        return  _Login();

    }

};

