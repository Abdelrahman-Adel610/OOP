#include "Book.h"

int Book::getRateAverage()
{
    return RatingAverage;
}

bool Book::checkIfAvailable()
{
    return state;
}

Author Book::getAuthorInfo()
{
    return author;
}

User Book::getBorrowerInfo()
{
    return Borrower;
}

string Book::getTitle()
{
    return Title;
}

string Book::getISBN()
{
    return ISBN;
}

string Book::getCategory()
{
    return Category;
}

void Book::setISBN(string s)
{
    try
    { 
        if (s.length() == 13)
            ISBN = s;
        else throw ("Inavlid ISBN ,");
    }
    catch (const char a[15])
    {
        cout << a << "Please entre the correct ISBN : \n";
        cin >> s;
        setISBN(s);
    }
}

void Book::setTitle(string s)
{
    Title = s;
}

void Book::setCategory(string s)
{
    '0'; '9';
    try
    {
        for (int i = 0; i < s.size(); i++)
        { 
            if (s[i] >= 48 && s[i] <= 57)
                throw("Ivalid input , please entre the correct category name : \n");
        }
    Category = s;
    }
    catch (const char a[54])
    {
        cout << a;
        cin >> s;
        setCategory(s);
    }
}

void Book::setRatingAverage(float s)
{
    try
    {
        if (s >= 0 && s <= 5)
            RatingAverage = s;
        else 
            throw("Ivalid input as rating range is from 1 to 5 , ");
    }
    catch(const char a[47])
    {
        cout << a << "please Entre the correct rating\n";
        cin >> s;
        setRatingAverage(s);
    }
}

void Book::setState(bool s)
{
    state = s;
}

void Book::setAuthor(Author s)
{
    cin >> s;
}

void Book::setborrower(User s)
{
    cin >> s;
}

void Book::display()
{
    cout << "The book " << "\" " << Title << "\"" << " is " << Category << " book\n";
    cout << "The International Standard Book Number is " << ISBN << endl;
    cout << "The Rating Average is " << RatingAverage << endl;
    cout << "---->The author's information : \n";
    cout << author;
    if (state)
    {
        cout << "The Book is available ! " << endl;
    }
    else
    {
        cout << "The Book isn't available \n";
        cout << "---->The Borrower's information : \n";
        cout << Borrower;
    }
 
}

Book::Book(const Book& a)
{
    author = a.author;
    Borrower = a.Borrower;
    Category = a.Category;
    ISBN = a.ISBN;
    RatingAverage = a.RatingAverage;
    state = a.state;
    Title = a.Title;
}

Book Book::operator=(Book& a)
{
    author = a.author;
    Borrower = a.Borrower;
    Category = a.Category;
    ISBN = a.ISBN;
    RatingAverage = a.RatingAverage;
    state = a.state;
    Title = a.Title;

    return (this);
}

Book::Book(bool State, string Title, string Category, string isbn, float Average, User b, const Author & a):state(State), Title(Title), Category(Category), ISBN(isbn), RatingAverage(Average), author(a), Borrower(b)
{
}


ostream& operator<<(ostream& out, Book&a)
{
    
        out << "The book " << "\" " << a.Title << "\"" << " is " << a.Category << " book\n";
        out << "The International Standard Book Number is " << a.ISBN<<endl;
        out << "The Rating Average is " << a.RatingAverage<<endl;
        out << "---->The author's information : \n";
        cout << a.author;
        if (a.state)
        {
            out << "The Book is available ! " << endl;
        }
        else
        {
            out << "The Book isn't available \n";
            out << "---->The Borrower's information : \n";
            cout << a.Borrower;
        }
        return out;
   
}

istream& operator>>(istream& in, Book&a)
{
    cout << "PLease entre the book's title : ";
    getline(cin >>ws, a.Title);
    cout << endl;
    c:
    try
    {
        string s;
    cout << "PLease entre the book's category : ";
    getline(in >> ws, s);  
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
            throw("Ivalid input , please entre the correct category name : \n");
    }
     a.Category=s;
    }
    catch (const char a[54])
    {
    cout << a;
    goto c;
    }
    cout << endl;
    b:
    try
    { 
    cout << "PLease entre the book's International Standard Book Number : ";
    string a;
    cin >> a;
    if (a.size() == 13)
    {

    }
    else throw ("Inavlid ISBN ,");
    }

    catch (const char b[15])
    {
        cout << b << "Please entre the correct ISBN : \n";
        goto b;
    }
    cout << endl;
a:
    try
    {
        cout << "PLease entre the book's Rating Average : ";
        float s;
        cin >> s;
        cout << endl;
        if(s >= 0 && s <= 5)
         a.RatingAverage=s;
        else throw("Ivalid input as rating range is from 1 to 5\n");
    }
    catch (const char a[45])
    {
        cout << a << "Please try again : ";
        goto a;
    }
    cout << "PLease Entre the author's information : \n";
    cin >> a.author;
    cout << endl;
    cout << "PLease entre the book's state (available==1,not available=0) : ";
    in >> a.state;
    cout << endl;
    if ((a.state))
    {
        cout << "There are no Borrowers the book is already available \n";
    }
    else
    {
        cout << "PLease entre the borrower information : \n";
        cin >> a.Borrower;
    }
    return in;
}
