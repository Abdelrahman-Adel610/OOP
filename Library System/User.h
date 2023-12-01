#pragma once
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class User
{
protected:
	string Name,Gendre,Email,Age;
private:
	string nationalID{};
	string Password;
    static long long ccollegeID;
    const long long collegeID;
    int day, month, year;

public:
	void generatePassword();
	void generateEmail();
	void setName(string s);
	void setAge(string a);
	void setGendre(string s);
	void setNational_ID(string s);
	void GenerateBirthDate();
	void display();
	void DispalyDateOfBirth();
	string getName();
	string getGendre();
	string getEmail();
	string getPassword();
	string getAge();
	long long getcollegeID();
	User operator =(const User &a);
	friend istream& operator>>(istream&in,User& a);
	friend ostream& operator<<(ostream&out,User& a);
	User();
	~User();
	User(const User& a);
	User(string NationalID, string name = "New User", string Age = "N/A", string Gendre = "N/A", long long collegeID = (++ccollegeID));
};

