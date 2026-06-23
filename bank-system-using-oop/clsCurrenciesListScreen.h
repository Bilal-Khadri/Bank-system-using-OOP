#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"

using namespace std;


class clsCurrenciesListScreen:protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\t| " << setw(30) << Currency.Country();
		cout << "\t| " << setw(15) << Currency.CurrencyCode();
		cout << "\t| " << setw(37) << Currency.CurrencyName();
		cout << "\t| " << setw(13) << Currency.Rate();
		cout << "|\n";
	}

public:

	static void ShowCurrenciesListScreen() {

		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string title, subtitle;

		title = "\tCurrencies List Screen";
		subtitle = "\t" + to_string(vCurrencies.size()) + " Currencie(s)";

		_DrawScreenHeader(title, subtitle);

		cout << "\t-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t| " << setw(30) << "Country";
		cout << "\t| " << setw(15) << "Code";
		cout << "\t| " << setw(37) << "Name";
		cout << "\t| " << setw(13) << "Rate ($)";
		cout << "|\n";
		cout << "\t-----------------------------------------------------------------------------------------------------------------------\n";

		for (clsCurrency& Currency : vCurrencies) {
			_PrintCurrency(Currency);
			
		}
		cout << "\t-----------------------------------------------------------------------------------------------------------------------\n";
	}
};

