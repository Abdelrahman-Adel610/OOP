#include "User.h"
long long User::ccollegeID = 92300;
void User::setName(string s)
{
	Name = s;
}
void User::setAge(string a)
{
	try
	{
		'0'; '9';
		if (a.size() > 4||a.size()<1) throw("Invalid input , please entre the correcr age \n");
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] <= 57 && a[i] >= 48)
				continue;
			else throw("Invalid input , please entre the correcr age \n");
		}
	Age = a;
	}
	catch (const char h[47])
	{
		cout << h;
		cin >> a;
		setAge(a);
	}
}

void User::setGendre(string  s)
{
	Gendre = s;
}

void User::setNational_ID(string s)
{
	nationalID = s;
}

void User::GenerateBirthDate()
{
	int* a = new int[7];
	for (int i = 0; i < 7; i++)
	{
		a[i] = nationalID[i] - '0';
	}
	if (a[0] == 2)
	{
		year = 1900 + (a[1] * 10 + a[2]);
	}
	if (a[0] == 3)
	{
		year = 2000 + (a[1] * 10 + a[2]);
	}
	month = a[3] * 10 + a[4];
	day = a[5] * 10 + a[6];
	delete[]a;
}

void User::display()
{
	cout << "Name : " << Name << '\n';
	cout << "Gendre : " << Gendre << '\n';
	cout << "Age : " << Age << '\n';
	cout << "Email : " << Email << '\n';
	cout << "Password : " << Password << '\n';
	cout << "College ID : " << collegeID << '\n';
	cout << "National ID : " << nationalID << '\n';
	cout << "Date of Birth : " << day<<'/'<<month<<'/'<<year << '\n';
}

void User::generatePassword()
{
	random_device rd;
	Password = "";
	mt19937 generator(rd());
	string a = "0123456789";
	uniform_int_distribution<>d1(0, a.length() - 1);
	for (int i = 0; i < 9; i++)
	{
		uniform_int_distribution<>d1(0, a.length() - 1);
		Password += a[d1(generator)];
	}
}

void User::generateEmail()
{
	random_device rd;
	Email = "";
	string p = "qwertyuiopasdfghjklmnbvcxzZXCVBNMLKJHGFDSAQWERTYUIOP";
	mt19937 generator(rd());
	uniform_int_distribution<>d2(0, p.length() - 1);
	for (int i = 0; i < 9; i++)
	{
		Email += p[d2(generator)];
	}
	Email+="@eng-st.cu.eg.edu";
}


User::User(string NID, string name, string Age, string Gendre, long long collegeID):nationalID(NID),Name(name),Age(Age),Gendre(Gendre),collegeID(collegeID)
{
	GenerateBirthDate();
	generatePassword();
	generateEmail();
}

string User::getName()
{
	return Name;
}
string User::getGendre()
{
	return Gendre;
}
string User::getEmail()
{
	return Email;
}
string User::getPassword()
{
	return Password;
}
void User::DispalyDateOfBirth()
{
	GenerateBirthDate();
	cout << "Date of Birth : " << day << '/' << month << '/' << year << '\n';
}
string User::getAge()
{
	return Age;
}
long long  User::getcollegeID()
{
	return collegeID;
}

User::User():collegeID(++ccollegeID),Name("New User"),Age("N/A"),Gendre("N/A"),Password("0000"),day(0),month(0),year(0)
{
	Email = "New_User_" + to_string(collegeID) + "@eng - st.cu.eg.edu";
}
User::User(const User& a) :collegeID(a.collegeID)
{
	Age = a.Age;
	ccollegeID = a.ccollegeID;
	day=a.day;
	Email = a.Email;
	Gendre = a.Gendre;
	month = a.month;
	Name = a.Name;
	nationalID = a.nationalID;
	Password = a.Password;
	year = a.year;
}
User::~User()
{
}
istream& operator>>(istream& in, User &a)
{
	cout << "Please Entre the User's Name : ";
	getline(cin >> ws, a.Name);
	cout << endl;
	cout << "Please Entre the User's Gendre : ";
	in >> a.Gendre;
	cout << endl;
	AA:
	try
	{
		cout << "Please Entre the User's Age : ";
		string b;
		in >> b;
		if (b.size() > 3 || b.size() < 1) throw("Invalid input , please entre the correcr age \n");
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] <= 57 && b[i] >= 48)
				continue;
			else throw("Invalid input , please entre the correcr age \n");
		}
		a.Age = b;
	}
	catch (const char h[47])
	{
		cout << h;
		goto AA;
	}
	cout << endl;
	X:
	try
	{
	cout << "Please Entre the User's National ID : ";
	string h;
	in >> h;
	if (h.size() != 14) throw("Invalid National ID , please Entre the correct one : \n");
	for (int i = 0; i < 14; i++)
	{
		'0'; '9';
		if (h[i] >= 48 && h[i] <= 57)
			continue;
		else throw("Invalid National ID , please Entre the correct one : \n");
	}
	a.nationalID = h;
	}
	catch (const char g[55])
	{
		cout << g;
		goto X;
	}
	cout << endl;
	a.GenerateBirthDate();
	a.generateEmail();
	a.generatePassword();
	return in;
}
ostream& operator<<(ostream& out, User& a)
{
	out << "Name : " << a.Name << '\n';
	out << "Gendre : " << a.Gendre << '\n';
	out << "Age : " << a.Age << '\n';
	out << "Email : " << a.Email << '\n';
	out << "Password : " << a.Password << '\n';
	out << "College ID : " << a.collegeID << '\n';
	out << "National ID : " << a.nationalID << '\n';
	out << "Date of Birth : " << a.day << '/' << a.month << '/' << a.year << '\n';
	return out;
}
User User::operator=(const User& a)
{
	Age = a.Age;
	ccollegeID = a.ccollegeID;
	day = a.day;
	Email = a.Email;
	Gendre = a.Gendre;
	month = a.month;
	Name = a.Name;
	nationalID = a.nationalID;
	Password = a.Password;
	year = a.year;
	return(*this);
}





