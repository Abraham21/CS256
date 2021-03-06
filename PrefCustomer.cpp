#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class PersonData {
private:
	string lastName;
	string firstName;
	string address;
	string City;
	string State;
	long int Zip;
	long int phone;
public:
	PersonData() {
		lastName = "";
		firstName = "";
		address = "";
		City = "";
		State = "";
		Zip = 0;
		phone = 0;
	}
	void setLastName(string);
	void setFirstName(string);
	void setAddress(string);
	void setCity(string);
	void setState(string);
	void setZip(long);
	void setPhone(long);
	string getLastName();
	string getFirstName();
	string getAddress();
	string getCity();
	string getState();
	long getZip();
	long getPhone();
};

void PersonData::setLastName(string lname)
{
	lastName = lname;
}

void PersonData::setFirstName(string fname)
{
	firstName = fname;
}

void PersonData::setAddress(string addr)
{
	address = addr;
}

void PersonData::setCity(string city)
{
	City = city;
}

void PersonData::setState(string state)
{
	State = state;
}

void PersonData::setZip(long z)
{
	Zip = z;
}

void PersonData::setPhone(long phno)
{
	phone = phno;
}

string PersonData::getLastName()
{
	return lastName;
}

string PersonData::getFirstName()
{
	return firstName;
}

string PersonData::getAddress()
{
	return address;
}

string PersonData::getCity()
{
	return City;
}

string PersonData::getState()
{
	return State;
}

long PersonData::getZip()
{
	return Zip;
}

long PersonData::getPhone()
{
	return phone;
}

class CustomerData :public PersonData
{
private:
	int customerNumber;
	bool mailingList;
public:
	CustomerData()
	{
		customerNumber = 0;
		mailingList = false;
	}
	void setCustomerNumber(int);
	void setMailingList(bool);
	int getCustomerNumber();
	bool getMailingList();
};

void CustomerData::setCustomerNumber(int num)
{
	customerNumber = num;
}

void CustomerData::setMailingList(bool list)
{
	mailingList = list;
}

int CustomerData::getCustomerNumber()
{
	return customerNumber;
}

bool CustomerData::getMailingList()
{
	return mailingList;
}

class PreferredCustomer :public CustomerData
{
private:
	double purchaseAmount;
	double discountLabel;
public:
	PreferredCustomer()
	{
		purchaseAmount = 0;
		discountLabel = 0;
	}
	void setPurchaseAmount();
	void setDiscountLabel();
	double getPurchaseAmount();
	double getDiscountLabel();
};

void PreferredCustomer::setPurchaseAmount()
{
	double amount;
	cout << "Enter amount spent by customer: ";
	cin >> amount;
	purchaseAmount = amount;
}

void PreferredCustomer::setDiscountLabel()
{
	if (purchaseAmount >= 500 && purchaseAmount < 1000)
		discountLabel = 5;
	else if (purchaseAmount >= 1000 && purchaseAmount < 1500)
		discountLabel = 6;
	else if (purchaseAmount >= 1500 && purchaseAmount < 2000)
		discountLabel = 7;
	else if (purchaseAmount >= 2000)
		discountLabel = 10;
}

double PreferredCustomer::getPurchaseAmount()
{
	return purchaseAmount;
}

double PreferredCustomer::getDiscountLabel()
{
	return discountLabel;
}

int main()
{
	PreferredCustomer customer;
	string name, addr, city, state;
	int custId;
	long Zcode, phno;
	cout << "Enter first name of customer: ";
	cin >> name;
	customer.setFirstName(name);
	cout << "Enter last name of customer: ";
	cin >> name;
	customer.setLastName(name);
	cout << "Enter address: ";
	cin >> addr;
	fflush(stdin);
	customer.setAddress(addr);
	cout << "Enter city name: ";
	cin >> city;
	customer.setCity(city);
	fflush(stdin);
	cout << "Enter state name: ";
	cin >> state;
	customer.setState(state);
	cout << "Enter zip code: ";
	cin >> Zcode;
	customer.setZip(Zcode);
	cout << "Enter phone number: ";
	cin >> phno;
	customer.setPhone(phno);
	cout << "Enter customer number: ";
	cin >> custId;
	customer.setCustomerNumber(custId);
	customer.setMailingList(true);

	customer.setPurchaseAmount();
	customer.setDiscountLabel();

	cout << "\n\n----- Customer Data -----" << endl;
	cout << "Customer first name: " << customer.getFirstName() << endl;
	cout << "Customer last name: " << customer.getLastName() << endl;
	cout << "Customer Number: " << customer.getCustomerNumber() << endl;
	cout << "Customer Address: " << customer.getAddress() << endl;
	cout << "City name: " << customer.getCity() << endl;
	cout << "State name: " << customer.getState() << endl;
	cout << "Zip code: " << customer.getZip() << endl;
	cout << "Phone number: " << customer.getPhone() << endl;
	cout << "Mailing list: " << customer.getMailingList() << endl;
	cout << "Customer Purchase amount: " << customer.getPurchaseAmount() << endl;
	cout << "Customer Discount on Every item: " << customer.getDiscountLabel() << "%\n" << endl;

	return 0;
}

