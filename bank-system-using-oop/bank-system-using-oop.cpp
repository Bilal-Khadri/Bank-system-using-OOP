#include <iostream>
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsTransferLogListScreen.h"
#include"clsCurrency.h"
#include"clsCurrencyExchangeMenueScreen.h"


using namespace std;


int main()
{


	while (1) {

		if (!clsLoginScreen::ShowLoginScreen())
			break;

	}
	return 0;

}

