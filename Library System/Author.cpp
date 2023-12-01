#include "Author.h"

void Author::setName(string s)
{
	name = s;
}

void Author::setDOB(string s)
{
	dateOfBirth = s;
}

void Author::setDOD(string s)
{
	dateOfDeath = s;
}

void Author::setNofWorks(int n)
{
	numberOfWorks = n;
}

void Author::display()
{
	cout << "Author's Name : " << name << endl;
	cout << "Author's Date of birth : " << dateOfBirth << endl;
	cout << "Author's Date of death : " << dateOfDeath << endl;
	cout << "Author's NO.Works: " << numberOfWorks << endl<<endl;
}

string Author::getName()
{
	return name;
}

string Author::getDOB()
{
	return dateOfBirth;
}

string Author::getDOD()
{
	return dateOfDeath;
}

int Author::getNofWorks()
{
	return numberOfWorks;
}

Author::Author(string name, string DOB, string DOD, int n) :name(name), dateOfBirth(DOB), dateOfDeath(DOD), numberOfWorks(n)
{
}

Author::Author(const Author& a)
{
	name = a.name;
	dateOfBirth = a.dateOfBirth;
	dateOfDeath = a.dateOfDeath;
	numberOfWorks = a.numberOfWorks;
}

Author::~Author()
{
}

Author Author::operator=(const Author& a)
{
	name = a.name;
	dateOfBirth = a.dateOfBirth;
	dateOfDeath = a.dateOfDeath;
	numberOfWorks = a.numberOfWorks;
	return(*this);
}

istream& operator>>(istream& in, Author & a)
{
	
	cout << "Entre the Name : " << endl;
	getline(cin >> ws, a.name);
	cout << endl;
	cout << "Entre the Date of birth : " << endl;
	getline(cin >> ws, a.dateOfBirth);	
	cout << endl;
	cout << "Entre the Date of death : " << endl;
	getline(cin >> ws, a.dateOfDeath);
	cout << endl;
	cout << "Entre the Number of works : " << endl;
	in >> a.numberOfWorks;
	return in;
}

ostream& operator<<(ostream& out, Author& a)
{
	out << "Author's Name : " <<a.name << endl;
	out << "Author's Date of birth : " <<a. dateOfBirth << endl;
	out << "Author's Date of death : " << a.dateOfDeath << endl;
	out << "Author's NO.Works: " <<a. numberOfWorks << endl<<endl;
	return out;
}


