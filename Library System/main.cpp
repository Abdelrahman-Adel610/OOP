#include"User.h"
#include"Author.h"
#include"Book.h"

int main()
{
	vector<User>users{};
	vector<Book>books{};

	a:
	cout << "1. Add Users\n2. Add Books\n3. Query on a subscription\n4. Borrow a Book\n5. Close\n";
	short int a;
	cin >> a;
	switch (a)
	{
	case 1:
	{
		cout << "How many users do you want to add ? \n";
		int n;
		cin >> n;
		while (n--)
		{
			User a;
			cin >> a;
			users.push_back(a);
		}
		cout << "Added successfully !\n\n";
		goto a;
	}
	case 2:
	{
		cout << "How many Books do you want to add ? \n";
		int n;
		cin >> n;
		while (n--)
		{
			Book a;
			cin >> a;
			books.push_back(a);
		}
		cout << "Added successfully !\n\n";
		goto a;
	}

	case 3:
	{
		cout << "Please Entre the student's name : ";
		string s{};
		getline(cin >> ws, s);
		for (int i = 0; i < users.size(); i++)
		{ 
			if (users[i].getName() == s)
			{
				cout << "Student is subscribing\n\n";
				goto a;
			}
		}
		    cout << "Student is not subscribing, do you want to add him to system?\n\n";
		goto a;
	}

	case 4:
	{
		cout << "Please Entre the book's Title :\n";
		string s{};
		getline(cin >> ws, s);
		for (int i{}; i < books.size(); i++)
		{
			if (books[i].getTitle() == s)
			{
				if (books[i].checkIfAvailable())
				{
					cout << "The book is available to borrow ! \n\n";
					User b;
					books[i].setborrower(b);
					books[i].setState(0);
				}
				else
					cout << "The book is already borrowed \n\n";
				goto a;
			}
		}
		cout << "Book is not found\n\n";
			goto a; 
	}
	case 5:
		{
		return 0;
		}
	}
}