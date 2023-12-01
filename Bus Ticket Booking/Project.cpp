#include <iostream>
using namespace std;
int main()
{
	long long x,id,y;
	page_1:
	cout << "Welcome to our bus ticket booking system.\nFor User: Press [1]\nFor Guest: press [2]\n1. User\n2. Guest\n";
	cin >> x;
	switch (x) 
	{
	
	case 1:
	{
		for (int i = 1; i <= 3; i++)
		{
			cout << "Please Entre your ID:\n";
			cin >> id;
				switch (id)
				{
				case 137:
				case 189:
				case 126:
				case 191:
					cout << "Successful Operation\n";
					return 0;
				case 0:goto page_1; break;
				default:
					cout << "Wrong ID, please try again.\n";
					break;
		
				 }
		}
	break;
	}
	case 2:
	{
		cout << "Choose a ticket from the following:\n1. Ticket number 1, 50 L.E.\n2. Ticket number 2, 30 L.E.\n3. Ticket number 3, 20 L.E.\n";
			cin >> y;
				switch(y)
				{
				   case 1:
				   case 2:
				   case 3:
					   cout << "Successful Operation";
					   return 0;
				   case 0:
					   goto page_1;
					   break;
					default:
						cout << "wrong choice\n";
						return 0;
				}
	break;
	}
	
	default:
		cout << "Wrong choice\n";
		return 0;

       

	}




}
