// DayModification.cpp
//Abraham Yepremian
//CS 256

#include <stdafx.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
static string date;

class DayOfYear {
private:
	int day;
	int countOfDay = 0;
	static string month[];
	int monthCounts[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	DayOfYear(int dayEntered) {
		if (dayEntered > 0 || dayEntered <= 365) {
			day = dayEntered;
		}
		else {
			exit(0);
		}
	}
	DayOfYear(string monthName, int day) {
		int index = 0;
		int position = -1;
		bool found = false;

		while (index < 12 && !found)
		{
			if (month[index] == monthName)
			{
				found = true;
				position = index;
			}
			index++;
		}
		if (found == false)
		{
			cout << "Enter a valid month.\n";
			exit(0);
		}

		if (day > monthCounts[position] || day < 0)
		{
			cout << "Incorrect number of a days!\n"
				<< monthName << " has " << monthCounts[position] << " days." << endl;
			exit(0);
		}
		else
		{
			for (int i = 0; i < position; i++)
			{
				countOfDay += monthCounts[i];
			}
			day = countOfDay + day;
		}
	}
	void print();

	DayOfYear operator ++ (); //PREFIX PROTOTYPE
	DayOfYear operator ++ (int); //POSTFIX PROTOTYPE
	DayOfYear operator -- (); //PREFIX PROTOTYPE
	DayOfYear operator -- (int); //POSTFIX PROTOTYPE

};

DayOfYear DayOfYear::operator++() //OVERLOAD PREFIX
{
	if (day == 365)
		day = 1;
	else
		day++;
	return *this;
}

DayOfYear DayOfYear::operator++(int) //OVERLOAD POSTFIX
{
	if (day == 365)
		day = 1;
	else
		day++;
	return *this;
}

DayOfYear DayOfYear::operator--() //OVERLOAD PREFIX
{
	if (day == 1)
		day = 365;
	else
		day--;
	return *this;
}

DayOfYear DayOfYear::operator--(int) //OVERLOAD POSTFIX
{
	if (day == 1)
		day = 365;
	else
		day--;
	return *this;
}

void DayOfYear::print()
{
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int init = 0, monthInit, day;

	for (int i = 0; i < 12; i++)
	{
		if (day < (init + (months[i] + 1)))
		{
			monthInit = i;
			day = day - init;
			break;
		}
		init += months[i];
	}
	cout << month[monthInit] << " " << day << endl;
}

string DayOfYear::month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	string monthName;
	int userDay;

	cout << "Constructor #2" << endl;
	cout << "Enter the day (0-365): " << endl;
	cin >> userDay;

	DayOfYear Day(userDay);
	Day.print();

	cout << endl << "Constructor #3 with Operator Overload" << endl;
	cout << "Enter month (string) and day (int) separated by a space: " << endl;
	cin >> monthName;
	cin >> userDay;

	DayOfYear overloadDay(monthName, userDay);

	overloadDay.print();

	cout << "Overloaded ++ Prefix: ";
	++overloadDay;
	overloadDay.print();

	cout << "Overloaded ++ Postfix: ";
	overloadDay++;
	overloadDay.print();

	cout << "Overloaded -- Prefix : ";
	--overloadDay;
	overloadDay.print();

	cout << "Overloaded -- Postfix : ";
	overloadDay--;
	overloadDay.print();

	return 0;
}
