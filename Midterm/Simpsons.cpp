// Simpsons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Human.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	//create the Simpson family
	Parent homer = new Human("Homer", 36, 'M');
	Parent march = new Human("March", 34, 'F');
	vector<Child> children = { lisa, bart, maggie };
	Child Lisa(March, Homer);
	Child Bart(March, Homer);
	Child Maggie(March, Homer);
	march.changeName(maggie, "Maggie");
	homer.changeName(bart, "Bart");
	homer.changeName(lisa, "Lisa");
	lisa.setAge(12);
	bart.setAge(10);
	maggie.setAge(3);
	lisa.setSex('F');
	bart.setSex('M');
	maggie.setSex('F');
	homer.setChildren(children);
	march.setChildren(children);
	//print out data for homer and march
	cout << homer.getName() << endl;
	cout << homer.getAge() << endl;
	cout << homer.getSex() << endl;
	cout << homer.work() << endl;
	cout << march.getName() << endl;
	cout << march.getAge() << endl;
	cout << march.getSex() << endl;
	cout << march.work() << endl;
	//print out data for children
	for (int i = 0; i < children.size(); i++) {
		cout << children[i].getName() << endl;
		cout << children[i].getAge() << endl;
		cout << children[i].getSex() << endl;
		cout << children[i].work() << endl << endl;
	}

    return 0;
}

