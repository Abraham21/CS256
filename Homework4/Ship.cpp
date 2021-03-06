// Ship.cpp : Defines the entry point for the console application.

#include <stdafx.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Ship {
protected:
	string name;
	string year;
public:
	Ship(string n, string y) {
		name = n;
		year = y;
	}
	Ship() {
		name = " ";
		year = "0";
	}
	virtual void print() {
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
	}
	void setName(string n) {
		name = n;
	}
	void setYear(string y) {
		year = y;
	}
	string getName() {
		return name;
	}
	string getYear() {
		return year;
	}
};

class CruiseShip : public Ship {
private:
	int numberOfPassengers;
public:
	CruiseShip(int n) {
		numberOfPassengers = n;
	}
	CruiseShip(string n, string y, int p) {
		name = n;
		year = y;
		numberOfPassengers = p;
	}
	virtual void print() override {
		cout << "Name: " << getName() << endl;
		cout << "Year: " << getYear() << endl;
		cout << "Number of Passengers: " << numberOfPassengers << endl;
	}
	void setPassengers(int p) {
		numberOfPassengers = p;
	}
	int getPassengers() {
		return numberOfPassengers;
	}
};

class CargoShip : public Ship {
private:
	int tonnage;
public:
	CargoShip(int n) {
		tonnage = n;
	}
	CargoShip(string n, string y, int t) {
		name = n;
		year = y;
		tonnage = t;
	}
	virtual void print() override {
		cout << "Name: " << getName() << endl;
		cout << "Year: " << getYear() << endl;
		cout << "Tonnage: " << tonnage << endl;
	}
	void setTonnage(int t) {
		tonnage = t;
	}
	int getTonnage() {
		return tonnage;
	}
};


int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	cout << "Chapter 15 Challenge #12: Ship, Cruise, Cargo Ship" << endl << endl;
	const int NUMBER_OF_SHIPS = 5;

	Ship *ships[NUMBER_OF_SHIPS] = {
		new Ship("Type 21 Frigate","1974"),
		new CargoShip("Colombo Express", "2005", 93750),
		new CruiseShip("Titanic", "1911", 3547),
		new Ship("T-Class Ferry", "1969"),
		new Ship("Pisa Class", "1932"),
	};

	cout << "Ships" << endl;
	cout << "-----" << endl;
	for (int i = 0; i < NUMBER_OF_SHIPS; i++) {
		ships[i]->print();
		cout << endl;
	}

	return 0;

}