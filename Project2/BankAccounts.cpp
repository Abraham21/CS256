//BankAccounts.cpp

#include "stdafx.h"
#include "BankAccounts.h"
#include <string>
#include <iostream>
using namespace std;

BankAccount::BankAccount(double initialBalance, double initialAnnualInterestRate) {
	originalBalance = initialBalance;
	balance = initialBalance;
	annualInterestRate = initialAnnualInterestRate;
	numberOfDepositsThisMonth = 0;
	numberOfWithdrawals = 0;
	monthlyServiceCharges = 0;
}

void BankAccount::deposit(double depositAmount) {
	balance += depositAmount;
	numberOfDepositsThisMonth++;
	cout << "After deposit, balance becomes: " << getBalance() << endl;
}

void BankAccount::withdraw(double withdrawAmount) {
	balance -= withdrawAmount;
	numberOfWithdrawals++;
	cout << "After withdrawal, balance becomes: " << getBalance() << endl;
}

void BankAccount::calcInt() {
	double monthlyInterestRate = annualInterestRate / 12;
	double monthlyInterest = balance * monthlyInterestRate;
	balance += monthlyInterest;
}

void BankAccount::monthlyProc() {
	balance -= monthlyServiceCharges;
	calcInt();
	numberOfWithdrawals = 0;
	numberOfDepositsThisMonth = 0;
	monthlyServiceCharges = 0;
}

double BankAccount::getNumberOfWithdrawals() {
	return numberOfWithdrawals;
}

double BankAccount::getBalance() {
	return balance;
}

double BankAccount::getOriginalBalance() {
	return originalBalance;
}

double BankAccount::getMonthlyServiceCharge() {
	return monthlyServiceCharges;
}

void BankAccount::monthStatistics() {
	cout << "\nStatistics for the month" << endl;
	cout << "Beginning balance was " << originalBalance << endl;
	cout << "Total amount of deposits: " << numberOfDepositsThisMonth << endl;
	cout << "Total amount of withdrawals: " << numberOfWithdrawals << endl;
	cout << "Service charges this month: " << monthlyServiceCharges << endl;
	cout << "Ending balance: " << balance << endl;
}

void BankAccount::setMonthlyServiceCharge(double newMonthlyServiceCharge) {
	monthlyServiceCharges = newMonthlyServiceCharge;
}

void BankAccount::setBalance(double newBalance) {
	balance = newBalance;
}

SavingsAccount::SavingsAccount(double initialBalance, double initialAnnualInterestRate) : BankAccount(initialBalance, initialAnnualInterestRate) {
	cout << "Savings account has been created with balance " << initialBalance << " and annual interest rate of " << initialAnnualInterestRate << "%." << endl;
	setStatus();
}

void SavingsAccount::setStatus() {
	if (getBalance() >= 25) {
		status = true;
	}
	else {
		status = false;
		cout << "Account inactive because balance went below $25" << endl;
	}
}

void SavingsAccount::withdraw(double withdrawAmount) {
	if (!status) {
		cout << "Unfortunately, you have an inactive account. No withdrawals allowed at this time." << endl;
	}
	else {
		BankAccount::withdraw(withdrawAmount);
		setStatus();
	}
}
void SavingsAccount::deposit(double depositAmount) {
	if (!status) {
		cout << "Account inactive because of low balance." << endl;
		cout << "Increase balance above $25 with deposit to activate account." << endl;
		BankAccount::deposit(depositAmount);
		setStatus();
	}
	else {
		BankAccount::deposit(depositAmount);
	}
}

void SavingsAccount::monthlyProc() {
	if (getNumberOfWithdrawals() > 4) {
		setMonthlyServiceCharge(1);
	}
	BankAccount::monthlyProc();
}

CheckingAccount::CheckingAccount(double initialBalance, double initialAnnualInterestRate) : BankAccount(initialBalance, initialAnnualInterestRate) {
	cout << "Checkings account has been created with balance " << initialBalance << " and annual interest rate of " << initialAnnualInterestRate << "%." << endl;
}
void CheckingAccount::withdraw(double withdrawAmount) {
	if (getBalance() - withdrawAmount < 0) {
		cout << "Checkings account balance went below $0." << endl;
		cout << "A $15 service charge wil be made on your account." << endl;
		setBalance(getBalance() - 15);
		setMonthlyServiceCharge(getMonthlyServiceCharge() + 15);
	}
	BankAccount::withdraw(withdrawAmount);
}
void CheckingAccount::monthlyProc() {
	setMonthlyServiceCharge(5 + (.1 * getNumberOfWithdrawals()));
	BankAccount::monthlyProc();
}