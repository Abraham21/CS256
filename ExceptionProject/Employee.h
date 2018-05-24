#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Employee {
private:
	//variables
	string employeeName;
	int employeeNumber;
	string hireDate;
public:
	//constructors
	Employee(string, int, string);
	Employee(string, int);
	//setter methods
	void setName(string);
	void setNumber(int);
	void setHireDate(string);
	//getter methods
	string getName();
	int getNumber();
	string getHireDate();
	//exception
	class InvalidEmployeeNumber {};
};