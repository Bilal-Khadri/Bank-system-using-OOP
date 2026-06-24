#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"





using namespace std;


class clsCurrencyExchangeMenueScreen:protected clsScreen
{

private:

	enum enCurrencyExchangeOption{eListCurrencies=1,eFindCurrency,
		UpdateRate,eCurrencyCalculator,eMainMenue};

	static short _ReadOption() {

		short option;

		cout << "Choose what do you want to do : ";
		option = clsInputValidate::ReadShortNumberBetween(1, 4);

		return option;
	}

	static void _ShowListCurrenciesScreen() {

		clsCurrenciesListScreen::ShowCurrenciesListScreen();
		//cout << "List Currencies will be here ..\n";

	}

	static void _ShowFindCurrencyScreen() {

		//cout << "Find Currency will be here ..\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}
	static void _ShowUpdateRateScreen() {

		//cout << "Updade Rate Screen will be here ..\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();

	}
	static void _ShowCurrencyCalulatorScreen() {

		cout << "Currency Calculator Screen will be here ..\n";

	}

	static void _GoToCurrencyExchangeMenue() {

		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();

	}

	static void _performCurrencyExchangeOption(enCurrencyExchangeOption Option) {

		switch (Option) {

		case enCurrencyExchangeOption::eListCurrencies:
			{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoToCurrencyExchangeMenue();

			break;
			}
		case enCurrencyExchangeOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoToCurrencyExchangeMenue();

			break;
		}

		case enCurrencyExchangeOption::UpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOption::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalulatorScreen();
			_GoToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOption::eMainMenue:
		{
			system("cls");
			// Main menue ..

			break;
		}
		}
	}

public:

	static void ShowCurrencyExchangeScreen() {

		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");
	
		cout << "\n";
		cout << setw(37) << left<< "" << "\t==============================\n";
		cout << setw(37) << left<< "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left<< "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left<< "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left<< "" << "\t[4] Currency Calcutator.\n";
		cout << setw(37) << left<< "" << "\t[5] Main Screen.\n";
		cout << setw(37) << left<< "" << "\t==============================\n";
		
		cout << setw(37) << left << "" << "\t";
		_performCurrencyExchangeOption(enCurrencyExchangeOption(_ReadOption()));
	}

};

