#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"


using namespace std;



class clsTransferLogListScreen:protected clsScreen
{

private:

	static void PrintData(clsBankClient::stTransferLogData Data)
	{
		cout << "\t\t";
		cout << left;

		cout << setw(23) << Data.Date;
		cout << "|" << setw(10) << Data.AccountNumber;
		cout << "|" << setw(10) << Data.DestinationAccountNumber;
		cout << "|" << setw(10) << Data.Amount;
		cout << "|" << setw(10) << Data.AcountBalance;
		cout << "|" << setw(10) << Data.DestinationAccountBalance;
		cout << "|" << setw(10) << Data.UserName;
		cout << '\n';
	}
public:

	static void ShowtransferLogListScreen() {

		vector< clsBankClient::stTransferLogData> vTransferLogList = clsBankClient::GetTransferLogList();

		string title = "\tTransfer Log list screen ";
		string subtitle = "\t\t" + to_string(vTransferLogList.size()) + " Record(s)";

		_DrawScreenHeader(title, subtitle);
		
		cout << "\n\t\t-------------------------------------------------------------------------------------\n";
		cout << "\t\t";
		cout << left;
		
		cout << setw(23) << "Date/Time";
		cout << "|" << setw(10) << "s.Accnt";
		cout << "|" << setw(10) << "d.Accnt";
		cout << "|" << setw(10) << "Amount";
		cout << "|" << setw(10) << "s.Balance";
		cout << "|" << setw(10) << "d.Balance";
		cout << "|" << setw(10) << "User";
		cout << '\n';
		cout << "\t\t-------------------------------------------------------------------------------------\n";

		for (clsBankClient::stTransferLogData& Log : vTransferLogList) {

			PrintData(Log);
		}
		cout << "\t\t-------------------------------------------------------------------------------------\n";

	}
};

