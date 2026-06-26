#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"


using namespace std;



class clsUpdateCurrencyScreen:clsScreen
{

private :

	static float _ReadNewRate() {

		cout << "\nEnter New Rate : ";
		float NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

	static void _PrintCurrencyCard(clsCurrency Currency) {

		cout << "\nCurrency Card : \n";
		cout << "-----------------------------\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate ($)   : " << Currency.Rate() << endl;
		cout << "-----------------------------\n";

		
	}

public :

	static void ShowUpdateCurrencyScreen() {

		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "\nEnter Currency Code : ";
		string Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code)) {

			cout << "\nCurrency was not found ! Choose another one : ";
			Code = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		_PrintCurrencyCard(Currency);


		char answer;
		cout << "\nAre you sure do you want to update the rate of this currency y/n? :";
		cin >> answer;
		
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n--------------------------\n";
			Currency.UpdateRate(_ReadNewRate());

			cout << "Currency Rate updated successfuly :)\n";
			_PrintCurrencyCard(Currency);

		}
	}
};

