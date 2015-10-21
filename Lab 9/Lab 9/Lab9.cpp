#include "Lab9.h"


// constructor
Person::Person(string &n, int a, char g, double m)
//setName(stringName), setAge(intAge), setGender(charGender), setHeight(doubleHeight)
{
	name = n;
	age = a;
	gender = g;
	meters = m;
}

Person::Person()
{
}

Person::Person(Person& p)
{
	name = p.name;
	age = p.age;
	gender = p.gender;
	meters = p.meters;
}

Person::~Person()
{
}

// set name
void Person::setName(string &n)
{
	name = n;
}
// set age
void Person::setAge(int a)
{
	age = a;
}
// set height
void Person::setHeight(double m) 
{
	meters = m;
}
// set gender
void Person::setGender(char g)
{
	gender = g;
}
// return name
string Person::getName()
{
	return name;
}
// return age
int Person::getAge()
{
	return age;
}
// return height/meters
double Person::getHeight()
{
	return meters;
}

// return gender
char Person::getGender()
{
	return gender;
}

istream &operator>>(istream &in, Person &p)
{
	cout << "name: ";
	in >> p.name;
	cout << "age: ";
	in >> p.age;
	cout << "gender: ";
	in >> p.gender;
	cout << "height in meters: ";
	in >> p.meters;
	return in;
}

ostream &operator<<(ostream &out, Person &p)
{
	out<< "name: "<<p.name<< endl;
	out<< "age: "<< p.age<< endl;
	out<< "gender: "<<p.gender<< endl;
	out<< "height in meters: "<<p.meters<< endl;
	return out;
}

void TestPerson::testAssignment()
{
	cout<<"Testing Assignemnt\n";
	Person doppel = *this;
	cout<<doppel;
}

void TestPerson::testExtraction()
{
	cout<<"Testing Extracion\n";
	cin >> *this;
	// print out if test passed or not
	//if ()
	//cout << "test case passed";
	//cout << "test case failed";

}

void TestPerson::testInsertion()
{
	cout<<"Testing Insertion\n";
	cout << *this;
	// print out if test passed or not
	//if
	//cout << "test case passed";
	//cout << "test case failed";

}