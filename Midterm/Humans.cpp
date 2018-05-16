//Humans.cpp, different classes such as generic human, parent, and child

#include "stdafx.h"
#include "Human.h"
#include <string>
#include <iostream>
using namespace std;

Human::Human() {
	name = "";
	age = 0;
	sex = 'M';
}

Human::Human(string n, int a, char s) {
	name = n;
	age = a;
	sex = s;
}

void Human::work() {
	//deals with work that human does
}

void Human::setName(string n) {
	name = n;
}

void Human::setAge(int a) {
	age = a;
}

void Human::setSex(char s) {
	sex = s;
}

string Human::getName() {
	return name;
}

int Human::getAge() {
	return age;
}

char Human::getSex() {
	return sex;
}

/*Parent::vector<Child>children() {
	//vector children
} */

void Parent::setChildren(Child c) {
	Child = c;
}

Child Parent::getChild() {
	return children;
}

Child::Child() {
	//default constructor
	Mom = new Parent;
	Dad = new Parent;
}

Child::Child(Parent mom, Parent dad) {
	Mom = mom;
	Dad = dad;
}

Child::changeName(string n) {
	name = n;
}



