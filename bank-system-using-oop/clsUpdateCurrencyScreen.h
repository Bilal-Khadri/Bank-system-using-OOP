#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"


using namespace std;



class clsUpdateCurrencyScreen:clsScreen
{

private :

	static void _PrintCurrencyCard(clsCurrency Currency) {

		cout << "\nCurrency Card : \n";
		cout << "-----------------------------\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate ($)   : " << Currency.Rate() << endl;
		cout << "-----------------------------\n";

	}

	static void _ShowResult(clsCurrency Currency) {

		if (!Currency.IsEmpty()) {

			cout << "\nCurrency Found :)\n";
			_PrintCurrencyCard(Currency);
		}

		else  cout << "\nCurrency was not found \n";
	}


public :

	static void ShowUpdateCurrencyScreen() {

		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "\nEnter Currency Code : ";
		string Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		_ShowResult(Currency);

		char answer;
		cout << "\nAre you sure do you want to update the rate of this currency y/n? :";
		cin >> answer;
		
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\nEnter New Rate : ";
			float NewRate = clsInputValidate::ReadFloatNumber();
			Currency.UpdateRate(NewRate);

			cout << "Currency Rate updated successfuly :)\n";
			_PrintCurrencyCard(Currency);

		}
	}
};

