#include <stdafx.h>
#include <iostream>
#include <string>
using namespace std;

static string date;

class DayOfYear {
private:
	int day;
	static string month[];
public:
	DayOfYear(int num)
	{
		if (num > 0 || num <= 365)
			day = num;
	}

	void print() {
		//days of month
		int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int start = 0, M, D;

		for (int i = 0; i < 12; i++)
		{
			if (day < (start + (Months[i] + 1)))
			{
				M = i;
				D = day - start;
				break;
			}
			start += Months[i];
		}
		// Display month-day format
		cout << month[M] << " " << D << endl;
	}
};

string DayOfYear::month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
	int number;
	cout << "Enter days as an integer: ";
	cin >> number;
	//initialize DayOfYear
	DayOfYear day(number);
	//call print method
	day.print();
}