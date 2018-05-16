//Human.h

#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Human {
private:
	string name;
	int age;
	char sex;
	string work;
	Human();
protected:
	Human(string n, int a, char s);
public:
	friend class Child;
	friend class Parent;
	virtual void work() = 0;
	//setters
	void setName(string n);
	void setAge(int a);
	void setSex(char s);
	void setWork(string w);
	//getters
	string getName();
	int getAge();
	char getSex();
	string getWork();
};

class Parent : public Human {
private:
	vector<Child> children;
public:
	void setChildren(Child c);
	Child getChild();
};

class Child : public Parent {
private:
	Parent Mom;
	Parent Dad;
	Child();
protected:
	void changeName(string n);
public:
	Child(Parent mom, Parent dad);
};