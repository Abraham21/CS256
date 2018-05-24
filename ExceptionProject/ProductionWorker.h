#pragma once
#include "stdafx.h"
#include "Employee.h"

class ProductionWorker : public Employee {
private:
	//variables
	int shift;
	double hourlyPayRate;
public:
	//constructors
	ProductionWorker(int, double, string, int, string);
	ProductionWorker(int, double, string, int);
	//setters
	void setShift(int);
	void setHourlyPayRate(double);
	//getters
	int getShift();
	double getHourlyPayRate();
	//exceptions
	class InvalidShift {};
	class InvalidPayRate {};
};