// ExceptionProject.cpp : Page 1024 Chapter 16 Number 16
// Author: Abraham Yepremian
#include "stdafx.h"
#include "Employee.h"
#include "ProductionWorker.h"
#include <string>
#include <iostream>
using namespace std;

//method to print out information from Employee object
void callEmployeeMethods(Employee employee) {
	cout << "\nEmployee Name is " << employee.getName() << endl;
	cout << "Employee Number is " << employee.getNumber() << endl;
	cout << "Employee Hire Date is " << employee.getHireDate() << endl;
}
//method to print out information from ProductionWorker object
void callProductionWorkerMethods(ProductionWorker pw) {
	cout << "\nProduction Worker Name is " << pw.getName() << endl;
	cout << "Production Worker is " << pw.getNumber() << endl;
	cout << "Production Worker Hire Date is " << pw.getHireDate() << endl;
	cout << "Production Worker Shift is " << pw.getShift() << endl;
	cout << "Production Worker Hourly Pay Rate is $" << pw.getHireDate() << endl;
}

int main() {
	//demonstrates invalid employee number exception
	try {
		Employee employee("Nima", 256, "May 5, 2005");
		callEmployeeMethods(employee);
		Employee employee2("Abraham", 21, "May 14, 2018");
		callEmployeeMethods(employee2);
		Employee employee3("Arnold", 15000, "June 15, 2011");
		callEmployeeMethods(employee3);
	}
	catch (Employee::InvalidEmployeeNumber) {
		cout << "\nInvalid Employee Number Exception" << endl;
	}
	catch (ProductionWorker::InvalidShift) {
		cout << "\nInvalid Shift Exception" << endl;
	}
	catch (ProductionWorker::InvalidPayRate) {
		cout << "\nInvalid Pay Rate Exception" << endl;
	}
	//demonstrates invalid shift number exception
	try {
		ProductionWorker pw(1, 15.75, "Jessica", 9923, "July 14, 2013");
		callProductionWorkerMethods(pw);
		ProductionWorker pw2(2, 24.96, "Ted", 442, "September 9, 2010");
		callProductionWorkerMethods(pw2);
		ProductionWorker pw3(0, 19.42, "John", 1242, "January 21, 1998");
		callProductionWorkerMethods(pw3);
	}
	catch (Employee::InvalidEmployeeNumber) {
		cout << "\nInvalid Employee Number Exception" << endl;
	}
	catch (ProductionWorker::InvalidShift) {
		cout << "\nInvalid Shift Exception" << endl;
	}
	catch (ProductionWorker::InvalidPayRate) {
		cout << "\nInvalid Pay Rate Exception" << endl;
	}
	//demonstrates invalid pay rate exception
	try {
		ProductionWorker pw4(1, -15, "Gilbert", 7532, "April 5, 2008");
		callProductionWorkerMethods(pw4);
	}
	catch (Employee::InvalidEmployeeNumber) {
		cout << "\nInvalid Employee Number Exception" << endl;
	}
	catch (ProductionWorker::InvalidShift) {
		cout << "\nInvalid Shift Exception" << endl;
	}
	catch (ProductionWorker::InvalidPayRate) {
		cout << "\nInvalid Pay Rate Exception" << endl;
	}

	return 0;
}
