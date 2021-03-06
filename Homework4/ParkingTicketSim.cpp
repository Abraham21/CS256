//ParkingTicketSim.cpp

#include <stdafx.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class ParkedCar {
private:
	string make, model, color, licenseNumber;
	int minutes;
public:
	ParkedCar(string m, string mo, string co, string license, int min) {
		make = m;
		model = mo;
		color = co;
		licenseNumber = license;
		minutes = min;
	}
	string getMake() {
		return make;
	}
	string getModel() {
		return model;
	}
	string getColor() {
		return color;
	}
	string getLicenseNumber() {
		return licenseNumber;
	}
	int getMinutes() {
		return minutes;
	}
};

class ParkingMeter {
private:
	int minutes;
public:
	ParkingMeter(int min) {
		minutes = min;
	}
	int getMinutes() {
		return minutes;
	}
};

class Enforcer {
private:
	string name;
	int badgeNumber;
public:
	Enforcer(string n, int badge) {
		name = n;
		badgeNumber = badge;
	}

	//return true if car stayed longer than meter
	bool checkTime(ParkedCar p, ParkingMeter m) {
		return (p.getMinutes() > m.getMinutes());
	}

	string getName() {
		return name;
	}

	int getBadgeNumber() {
		return badgeNumber;
	}

};

class ParkingTicket {
private:
	string make, model, color, licenseNum, name;
	int fine, badgeNumber, carMins, meterMins;
public:
	ParkingTicket(ParkedCar car, ParkingMeter meter, Enforcer po) {
		make = car.getMake();
		model = car.getModel();
		color = car.getColor();
		licenseNum = car.getLicenseNumber();
		carMins = car.getMinutes();
		meterMins = meter.getMinutes();
		name = po.getName();
		badgeNumber = po.getBadgeNumber();

		if ((carMins - meterMins) <= 60) {
			fine = 25;
		}
		else {
			int extraHours = (int)ceil((double)((carMins - 60) / 60));
			fine = (extraHours * 10) + 25;
		}
	}

	void print() {
		cout << "Make: " << make << endl;
		cout << "Model: " << model << endl;
		cout << "Color: " << color << endl;
		cout << "License Number: " << licenseNum << endl;
		cout << "Time Stayed: " << carMins << " minutes" << endl;
		cout << "Meter Reading: " << meterMins << " minutes" << endl;
		cout << "Officer Name: " << name << endl;
		cout << "Officer Badge Number: " << badgeNumber << endl;
		cout << "Fine: $" << fine << endl;
		cout << endl;
	}
};

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	cout << endl << "Chapter 14 Challenge #14 Parking Ticket Sim" << endl << endl;
	ParkedCar c("Tesla", "ModelS", "Blue", "12TE5A7", 117);
	ParkingMeter m1(60);
	Enforcer p("Eric Thomas", 429876);
	if (p.checkTime(c, m1) == true) {
		cout << p.getName() << " has issued a ticket." << endl;
		cout << "Ticket details: " << endl;
		ParkingTicket t(c, m1, p);
		t.print();
	}

	ParkedCar c2("Lexus", "CT200H", "Gray", "IUE4728", 190);
	ParkingMeter m2(60);
	Enforcer p2("Monica Alan", 985243);
	if (p2.checkTime(c2, m2) == true) {
		cout << p2.getName() << " has issued a ticket." << endl;
		cout << "Ticket details" << endl;
		cout << "--------------" << endl;
		ParkingTicket t2(c2, m2, p2);
		t2.print();
	}

	return 0;

}