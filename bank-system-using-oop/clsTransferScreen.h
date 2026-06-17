#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"Global.h"
#include"clsInputValidate.h"


using  namespace std;

class clsTransferScreen:protected clsScreen
{

private:
	
	static void _PrintClientCard(clsBankClient client) {

		cout << "\nClient Card : \n";
		cout << "\n----------------------------------\n";
		cout << "Full Name : " << client.FullName() << "\n";
		cout << "Acc. Number : " << client.AccountNumber() << "\n";
		cout << "Balance : " << client.AccountBalance << "\n";
		cout << "----------------------------------\n";

	}

	static clsBankClient ReadClientAccountNumber(string text) {

		string account_number;

		cout << "\nPlease Enter account number to transfer "<<text<<" : ";
		account_number = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(account_number)) {

			cout << "\nClient was not found Enter again : ";
			cin >> account_number;
			
		}
		clsBankClient Client = clsBankClient::Find(account_number);
		_PrintClientCard(Client);
		return Client;
	}
	static float ReadAmount(clsBankClient Client) {

		float amount;

		cout << "Enter Amount : ";
		cin >> amount;

		while (amount > Client.AccountBalance) {
			{
				cout << "Amount exceeds the balance try another one : ";
				cin >> amount;
			}
		}return amount;
	}

public:

	static void ShowTransferScreen() {

		_DrawScreenHeader("\tTranster screen ");

		clsBankClient Client = ReadClientAccountNumber("from");
		clsBankClient DestinationClient = ReadClientAccountNumber("to");

		float amount = ReadAmount(Client);

		char answer;
		cout << "Are you sure do you want to perform this operation y/n? : ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			Client.Transfer(amount, DestinationClient);
			cout << "\nTransfer done successfully \n";

			_PrintClientCard(Client);
			_PrintClientCard(DestinationClient);

		}
		else cout << "\nTransfer failed \n";
	}


};

