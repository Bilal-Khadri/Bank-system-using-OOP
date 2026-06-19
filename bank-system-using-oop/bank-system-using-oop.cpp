#include <iostream>
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsTransferLogListScreen.h"
#include"clsCurrency.h"


using namespace std;

static void PrintCurrency(clsCurrency c) {

	cout << "\n---------------------------\n";
	cout << "Country   : " << c.Country() << endl;
	cout << "Code      : " << c.CurrencyCode() << endl;
	cout << "Name      : " << c.CurrencyName() << endl;
	cout << "Rate (1$) : " << c.Rate() << endl;
	cout << "---------------------------\n";

}
int main()
{

	clsCurrency C = clsCurrency::FindByCode("egp");

    PrintCurrency(C);
	



















	/*while (1) {

		if (!clsLoginScreen::ShowLoginScreen())
			break;

	}
	return 0;*/

}

