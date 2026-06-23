#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"



using namespace std;


class clsFindCurrencyScreen:protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency) {

		cout << "\n-----------------------------\n";
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

public:

	static void ShowFindCurrencyScreen() {

		_DrawScreenHeader("\tFind Currency Screen");

		short option;
		cout << "Find By : \n\n[1] Code \n[2] Country \n_";

		cin >> option;
		while (option > 2 || option < 1) {

			cout << "\nInvalid choice Enter again : ";
			cin >> option;
		}
		switch (option) {

		case 1:
		{
			cout << "\nPlease Enter Currency Code : ";
			string Code = clsInputValidate::ReadString();
			//if Currency found print it else will print Not found.
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			_ShowResult(Currency);
			break;

		}
		case 2:
		{
			cout << "\nPlease Enter Country : ";
			string Country = clsInputValidate::ReadString();
			//same think here if Currency found by country (this time) print it other than this say "Not found".
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
			break;
		}
		}
	}

};

