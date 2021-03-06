// GameOf21.cpp : Defines the entry point for the console application.
//

#include <stdafx.h>
#include <cstdlib> // For rand and srand
#include <ctime> // For the time function
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Die {
private:
	int sides;
	int value;
public:
	Die(int numSides) {
		unsigned seed = time(0);
		srand(seed);
		sides = numSides;
		roll();
	}
	void roll() {
		const int MIN_VALUE = 1;
		value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
	}
	int getSides() {
		return sides;
	}

	int getValue() {
		return value;
	}
};

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	cout << "Chapter 13 Challenge #18: A Game of 21." << endl << endl;
	bool ongoing = true;
	char input;
	Die dice1(6); //Two six sided die
	Die dice2(6);
	int playerTotal = 0;
	int compTotal = 0;

	cout << "Game of 21" << endl;
	cout << "----------" << endl;
	while (ongoing) {
		dice1.roll();
		compTotal += dice1.getValue();
		cout << "Computer has rolled." << endl;
		if (compTotal > 21) {
			cout << "Your Points: " << playerTotal << endl;
			cout << "Computer's Points: " << compTotal << endl;
			cout << "Computer lost!  You are the winner!." << endl;
			exit(0);  //exit to avoid break print statement.
		}
		cout << "Your Points: " << playerTotal << endl;
		cout << "Type y to roll, type n to stay." << endl;
		cin >> input;

		if (input == 'y') {
			dice2.roll();
			playerTotal += dice2.getValue();
			if (playerTotal > 21) {
				cout << "You rolled " << dice2.getValue() << "." << endl;
				cout << "Your Points: " << playerTotal << endl;
				cout << "Computer's Points: " << compTotal << endl;
				cout << "Game over! You lose." << endl;
				exit(0); //exit to avoid print statement
			}
			else {
				cout << "You rolled " << dice2.getValue() << "." << endl;
			}
		}
		else if (input == 'n') {
			ongoing = false;
		}
	}
	if (playerTotal > compTotal) {
		cout << "Your Points: " << playerTotal << endl;
		cout << "Computer's Points: " << compTotal << endl;
		cout << "You are the winner!" << endl;
		ongoing = false;
	}
	else {
		cout << "Your Points: " << playerTotal << endl;
		cout << "Computer's Points: " << compTotal << endl;
		cout << "Game over! You lose!" << endl;
		ongoing = false;
	}

	return 0;

}