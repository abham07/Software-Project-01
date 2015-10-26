// SWDesignOneAssignOne_Test.cpp : Defines the entry point for the console application.
/*
	BY: ABAD HAMEED
	ASSIGNMENT #1
	DATE: FEBRUARY 5, 2015

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class MainMenu;
class TransactionMenu
{
private:
	int i;
	string name;
	int accountNumber;
	MainMenu *theMainMenu;
	float balance = 500.00;
public:
	TransactionMenu::TransactionMenu(int accNum, MainMenu *mainMenu)
	{
		accountNumber = accNum;
		theMainMenu = mainMenu;
	}
	float TransactionMenu::GetBalance()
	{
		return balance;
	}
	void TransactionMenu::SetBalance(float i)
	{
		balance = i;
	}
	int TransactionMenu::GetAccNum()
	{
		return accountNumber;
	}
	void TransactionMenu::DepositFunds(float i)
	{
		balance += i;
	}
	void TransactionMenu::WithdrawFunds(float i)
	{
		if ((balance - i) >= 0) 
		{
			balance -= i;
		}
		else
		{
			cout << "\nSorry! Funds not available.\n";
		}
	}
};

class MainMenu
{
private:
	vector<TransactionMenu> account;
public:
	void addAccount(int accNum)
	{
		TransactionMenu newAccount = TransactionMenu(accNum, this);
		account.push_back(newAccount);
	}

	MainMenu::MainMenu()
	{
		int choice;
		int accNum;
		int flag;
		float amount;

		while (true)
		{
			system("CLS");

			cout << "Welcome!\n\nPlease enter account No.: ";
			cin >> accNum;
			addAccount(accNum);

			flag = 0;
			system("CLS");

			while (flag != 1)
			{
				cout << "Here are your options:\n\n1. Deposit Funds\n2. Withdraw Funds\n3. Determine Balance\n4. Exit\n\n";
				cout << "Please select one of the above options: ";
				cin >> choice;

				accNum = account[account.size() - 1].GetAccNum();
				
				switch (choice)
				{
				case 1:
				{
					system("CLS");
					cout << "Deposit Funds!\n";
					cout << "\n\nPlease enter the deposit amount: $";
					cin >> amount;

					account[account.size() - 1].DepositFunds(amount);
					amount = account[account.size() - 1].GetBalance();

					cout << "\n\nTransaction Complete!\nThe new balance for account " << accNum << " is $" << std::fixed << std::setprecision(2) << amount << ".\n\n";
					system("pause");
					system("CLS");
					break;
				}
				case 2:
				{
					system("CLS");
					cout << "Withdraw Funds!\n";
					cout << "\n\nPlease enter the withdrawl amount: $";
					cin >> amount;

					account[account.size() - 1].WithdrawFunds(amount);
					amount = account[account.size() - 1].GetBalance();

					cout << "\n\nTransaction Complete!\nThe new balance for account " << accNum << " is $" << std::fixed << std::setprecision(2) << amount << ".\n\n";
					system("pause");
					system("CLS");
					break;
				}
				case 3:
				{
					system("CLS");
					cout << "Determine Balance!\n";
					amount = account[account.size() - 1].GetBalance();
					cout << "\nThe current balance for account " << accNum << " is $" << std::fixed << std::setprecision(2) << amount << ".\n\n";
					system("pause");
					system("CLS");
					break;
				}
				case 4:
				{
					system("CLS");
					cout << "\n\nExit!\n";
					flag = 1;
					break;
				}
				default:
				{
					cout << "\n\nPlease make correct selection. ";
					system("pause");
					system("CLS");
					break;
				}
				}
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	MainMenu menu;
}
