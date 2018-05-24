#include "stdafx.h"
#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(string name, int number, string date) {
	employeeName = name;
	if (number < 0 || number > 9999) {
		throw InvalidEmployeeNumber();
	}
	else {
		employeeNumber = number;
	}
	hireDate = date;
}

Employee::Employee(string name, int number) {
	employeeName = name;
	if (number < 0 || number > 9999) {
		throw InvalidEmployeeNumber();
	}
	else {
		employeeNumber = number;
	}
}

void Employee::setName(string name) {
	employeeName = name;
}

void Employee::setNumber(int num) {
	if (num < 0 || num > 9999) {
		throw InvalidEmployeeNumber();
	}
	else {
		employeeNumber = num;
	}
}

void Employee::setHireDate(string date) {
	hireDate = date;
}

string Employee::getName() {
	return employeeName;
}

int Employee::getNumber() {
	return employeeNumber;
}

string Employee::getHireDate() {
	return hireDate;
}