//BankAccounts.h

#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class BankAccount {
private:
	double originalBalance;
	double balance;
	double numberOfDepositsThisMonth;
	double numberOfWithdrawals;
	double annualInterestRate;
	double monthlyServiceCharges;
//access within this class and its children
protected:
	BankAccount(double initialBalance, double initialAnnualInterestRate);
public:
	//bank account functionality
	virtual void deposit(double depositAmount);
	virtual void withdraw(double withdrawAmount);
	virtual void calcInt();
	virtual void monthlyProc();
	//method to display statistics for the month
	void monthStatistics();
	//setters
	void setMonthlyServiceCharge(double newMonthlyServiceCharges);
	void setBalance(double newBalance);
	//getters
	double getNumberOfWithdrawals();
	double getBalance();
	double getOriginalBalance();
	double getMonthlyServiceCharge();
};

class SavingsAccount : public BankAccount {
private:
	bool status;
public:
	SavingsAccount(double initialBalance, double initialAnnualInterestRate);
	//setStatus method will check balance amount to determine account active or inactive
	void setStatus();
	void withdraw(double withdrawAmount);
	void deposit(double depositAmount);
	void monthlyProc();
};

class CheckingAccount : public BankAccount {
public:
	CheckingAccount(double initialBalance, double initialAnnualInterestRate);
	void withdraw(double withdrawAmount);
	void monthlyProc();
};