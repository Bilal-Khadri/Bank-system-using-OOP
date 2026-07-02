#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


using namespace std;


class clsCurrencyCalculatorScreen:protected clsScreen
{

private:



	static void _PrintCurrencyCard(clsCurrency Currency,string message) {

		cout <<message<<" :\n";
		cout << "-----------------------------\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate ($)   : " << Currency.Rate() << endl;
		cout << "-----------------------------\n";

	}

	static clsCurrency _GetCurrency(string CurrencyNumber) {

		cout << "\nEnter " << CurrencyNumber << " Code :";
		string Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurency was not found ! Choose another :";
			Code = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		return Currency;
	}

	static float _ReadAmount() {

		cout << "\nEnter Amount to Exchange : ";
		float Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo) {

		cout << "\n";
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo)
			<< " " << CurrencyTo.CurrencyCode() << endl;
	}

public:

	static void ShowCurrencyCalculatorScreen() {

		char answer = 'n';

		do{

			system("cls");
		_DrawScreenHeader("\tCurrency Claculator Screen");

		clsCurrency CurrencyFrom = _GetCurrency("Currency 1");
		clsCurrency CurrencyTo = _GetCurrency("Currency 2");

		float Amount = _ReadAmount();
		
		_PrintCurrencyCard(CurrencyFrom, "Convert From");
		_PrintCurrencyCard(CurrencyTo, "To");

		_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation y/n? :";
			cin >> answer;

		} while (answer=='y'||answer=='Y');

	}



};

