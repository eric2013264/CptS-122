#ifndef LAB9_H
#define LAB9_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
using std::cout;
using std::cin;
using std::string;
using std::istream;
using std::ostream;
using std::endl;

// Create a base class called Person, which has private data members for a name, 
// age, gender, and height. Implement a constructor, copy constructor, destructor,
// overloaded assignment operator, overloaded stream insertion and extraction 
// operators that are friends to the class, and getters and setters. 
// See Task 2 for testing this class.
class Person
{
public:
	Person();
	Person(string &n, int a, char g, double m); 
	Person(Person& p);
	~Person();
	// setters
	void setName(string &n); // sets name
	void setAge(int); // sets age
	void setGender(char);
	void setHeight(double);
	// getters
	string getName(); // return name
	int getAge(); // return age
	char getGender();
	double getHeight();


	Person& operator = (Person& p);
	// extraction
	friend istream &operator>>(istream& in, Person& p);
	// Insertion
	friend ostream &operator<<(ostream& out, Person& p);

// only friends or inheriting from it can access it whereas private is friend only
protected:
	string name;
	int age;
	char gender;
	double meters;
};

class TestPerson: public Person
{
public:
	void testAssignment();
	void testExtraction();
	void testInsertion();
};

//class Student : public Person
//{
//public:
//	Student();
//	~Student();
//
//	// setters getters and 4 other task functions
//	Student& operator = (Student& s);
//	friend istream& operator>>(istream& in, Student& s);
//	friend ostream& operator<<(ostream& out, Student& s);
//private:
//	int numCoursesFinished;
//	int cumulativeCredits;
//	Course currentCArr[20];
//};
//
#endif