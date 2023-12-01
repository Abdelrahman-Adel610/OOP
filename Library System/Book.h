#pragma once
#include"User.h"
#include"Author.h"
using namespace std;
class Book
{
protected :
	float RatingAverage;
	string Title,ISBN,Category;
	Author author;
	User Borrower;
	bool state=1;
public:
	int getRateAverage();
	bool checkIfAvailable();
	Author getAuthorInfo();
	User getBorrowerInfo();
	string getTitle();
	string getISBN();
	string getCategory();

	void setISBN(string s);
	void setTitle(string s);
	void setCategory(string s);
	void setRatingAverage(float s);
	void setState(bool s);
	void setAuthor(Author s);
	void setborrower(User s);
	void display();

	Book(bool State = 0, string Title = "Undefined", string Category = "General", string isbn = "###-#-##-######-#", float Average = 0, User b=User(), const Author& a=Author());
 Book( const Book& a);

	Book operator=(Book& a);
	friend ostream& operator<<(ostream& out, Book&a);
	friend istream& operator>>(istream& in, Book&a);
};

