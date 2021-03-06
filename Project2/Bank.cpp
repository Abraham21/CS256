// Bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BankAccounts.h"
#include <string>
#include <iostream>
using namespace std;

void printMenu() {
	cout << "\nMenu Options" << endl;
	cout << "1. Deposit into Savings Account" << endl;
	cout << "2. Withdraw from Savings Account" << endl;
	cout << "3. Deposit into Checkings Account" << endl;
	cout << "4. Withdraw from Checkings Account" << endl;
	cout << "5. Show Savings Account Statistics for the month" << endl;
	cout << "6. Show Checkings Account Statistics for the month" << endl;
	cout << "7. Exit Program" << endl;
	cout << "Please enter integer from menu (1-7): " << endl;
}

int main() {
	double initialDeposit, interestRate;

	//savings account
	cout << "Enter an initial deposit for your savings account" << endl;
	cin >> initialDeposit;
	cout << "Enter annual interest rate for your savings account" << endl;
	cin >> interestRate;
	SavingsAccount savings(initialDeposit, interestRate);

	//checking account
	cout << "Enter an initial deposit for your checking account" << endl;
	cin >> initialDeposit;
	cout << "Enter annual interest rate for your checking account" << endl;
	cin >> interestRate;
	CheckingAccount checking(initialDeposit, interestRate);

	double depositAmount, withdrawalAmount;

	//Deposit and withdraw for savings account
	cout << "Enter a deposit amount for your savings account" << endl;
	cin >> depositAmount;
	savings.deposit(depositAmount);
	cout << "Enter a withdrawal amount for your savings account" << endl;
	cin >> withdrawalAmount;
	savings.withdraw(withdrawalAmount);

	//Deposit and withdraw for checking account
	cout << "Enter a deposit amount for your checking account" << endl;
	cin >> depositAmount;
	checking.deposit(depositAmount);
	cout << "Enter a withdrawal amount for your checking account" << endl;
	cin >> withdrawalAmount;
	checking.withdraw(withdrawalAmount);

	//Example of showing statistics for the month
	cout << "Savings Account" << endl;
	savings.monthStatistics();
	cout << "Checking Account" << endl;
	checking.monthStatistics();

	int choice = 0;
	do {
		printMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter a deposit amount for your savings account" << endl;
			cin >> depositAmount;
			savings.deposit(depositAmount);
			break; 
		case 2:
			cout << "Enter a withdrawal amount for your savings account" << endl;
			cin >> withdrawalAmount;
			savings.withdraw(withdrawalAmount);
			break;
		case 3: 
			cout << "Enter a deposit amount for your checking account" << endl;
			cin >> depositAmount;
			checking.deposit(depositAmount);
			break;
		case 4:
			cout << "Enter a withdrawal amount for your checking account" << endl;
			cin >> withdrawalAmount;
			checking.withdraw(withdrawalAmount);
			break;
		case 5:
			cout << "Savings Account" << endl;
			savings.monthStatistics();
			break;
		case 6:
			cout << "Checking Account" << endl;
			checking.monthStatistics();
			break;
		case 7:
			cout << "Thank you for using the program." << endl;
			break;
		default:
			cout << "Number is out of range. Try again." << endl;
			break;
		}

	} while (choice != 7);
	
	return 0;
}