#include <iostream>
#include "clsLoginScreen.h"


using namespace std;


int main()
{

	while (1) {

		if (!clsLoginScreen::ShowLoginScreen())
			break;

	}
	return 0;
}

