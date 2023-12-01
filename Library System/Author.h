#pragma once
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
using namespace std;
class Author
{
protected:
	string name , dateOfBirth , dateOfDeath ;
	int numberOfWorks;
public:
	void setName(string s);
	void setDOB(string s);
	void setDOD(string s);
	void setNofWorks(int n);

	void display();
	string getName();
	string getDOB();
	string getDOD();
	int getNofWorks();

	Author(string name = "Undefined", string DOB = "DD/MM/YYYY", string DOD = "DD/MM/YYYY", int n = 0);
	Author(const Author& a);
	~Author();

	Author operator=(const Author& a);
	friend istream& operator>>(istream& in, Author &a);
	friend ostream& operator<<(ostream& out, Author &a);

};

