
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
int main()
{
	vector < pair<string, int> > c1{0};
a:
	cin.tie(NULL);
	int CH = 0;
	cout << "1. Add students to system" << '\n' << "2. Modify a name or a grade" << '\n' << "3. Reset a grade" << '\n' << "4. Get a student's grade" << '\n' << "5. Get all grades" << '\n' << "6. Close" << '\n';
	cin >> CH;
	switch (CH)
	{
	case 1:
	{
		cout << "1. Read data from file"<<'\n'<<"2. I will input data"<<'\n';
		int x;
		//cin.ignore(-1, '\n');
		cin >> x;
		switch (x)
		{
		case 1:
		{
			ifstream file("students.txt");
			if (file.fail())
			{
				cout << "Error:Can't reach the file! "<<'\n';
				goto a;
			}
			else
			{
				cout << "Please entre the students number:" << '\n';
				int n;
				cin >> n;
				while (n--)
				{
					string s; int z;
					getline(file,s);
					for (int i=0;i < c1.size(); i++)
						if (c1[i].first == s)
						{
							cout << "Do you mean to modify his grade?" << '\n' << '\n';
							goto a;
						}
					file >> z;
					if (z < 0 || z>1500)
					{
						cout << "Invalid Range!" << '\n';
						for (int i = 1; i <= 3; i++)
						{
							cout << "Please try again:" << '\n';
							//cin.ignore(-1, '\n');
							cin >> z;
							if (!(z < 0 || z>1500)) goto c;
							else cout << "Invalid Range!" << '\n';
						}
						cout << '\n';
						goto  a;
					c:
						c1.push_back({ s,z });
					}
					c1.push_back({ s,z });
					file.ignore();
				}
				goto a;

			}
		}
		case 2:
		{
			cout << "Please entre the students number:" << '\n';
			int n;
			//cin.ignore(-1, '\n');
			cin >> n;
			cin.ignore();
			while (n--)
			{
				cout << "Please entre the full name :" << '\n';
				string s; int z;
				//cin.ignore();
				getline(cin, s);
				for (int i = 0; i < c1.size(); i++)
				{
					if (s == c1[i].first)
					{
						cout << "Do you mean to modify his grade?" << '\n' << '\n';
						goto a;
					}
				}
				cout << "Please entre a valid degree from 1 to 1500" << '\n';
				//cin.ignore(-1, '\n');
				cin >> z;
				if (z < 0 || z>1500)
				{
					cout << "Invalid Range!" << '\n';
					for (int i = 1; i <= 3; i++)
					{
						cout << "Please try again:" << '\n';
						//cin.ignore(-1, '\n');
						cin >> z;
						if (!(z < 0 || z>1500)) goto b;
						else cout << "Invalid Range!" << '\n';
					}
					cout << '\n';
					goto  a;

				}
			b:
				c1.push_back({ s,z });
				cin.ignore();
		
			}
		}
		}

		cout << "Students were successfully added to system." << '\n' << '\n';
		goto a;
	}

	case 2:
	{
		cout << "Please entre the name" << '\n';
		string s;
		cin.ignore();
		getline(cin, s);
		for (int i = 0; i < c1.size(); i++)
		{
			if (s == c1[i].first)
			{
				int z = 0;
				cout << "1. Modify Name" << '\n' << "2. Modify grade" << '\n';
				cin.ignore(-1, '\n');
				cin >> z;
				switch (z)
				{
				case 1:
				{
					string z;
					cout << "Please entre the modified name:" << '\n';
					cin.ignore();
					getline(cin, z);
					c1[i].first = z;
					cout << "Students data was successfully modified" << '\n' << '\n';
					goto a;
				}
				case 2:
				{
					int z;
					cout << "Please entre the modified degree:" << '\n';
					//cin.ignore(-1, '\n');
					cin >> z;
					if (z > 1500 || z < 0)
					{
						for (int i = 1; i <= 3; i++)
						{
							cout << "Invalid Range,please try again:" << '\n';
							cin.ignore(-1, '\n');
							cin >> z;
							if (!(z > 1500 || z < 0))
								goto k;
						}
						cout << '\n';
						goto a;
					}
				k:
					c1[i].second = z;
					cout << "Students data was successfully modified" << '\n' << '\n';
					goto a;
				}

				}
			}
		}
		cout << "Student isn't assigned! do you want to add him ?" << '\n' << '\n';
		goto a;
	}
	case 3:
	{
		string s;
		cout << "Please entre the target student's name:" << '\n';
		cin.ignore();
		getline(cin, s);
		for (int i = 0; i < c1.size(); i++)
		{
			if (c1[i].first == s)
			{
				c1[i].second = 0;
				cout << "The student's degree has been reseted successfully." << '\n' << '\n';
				goto a;
			}
		}
		cout << "Student isn’t assigned yet!" << '\n' << '\n';
		goto a;
	}
	case 4:
	{
		string s;
		cout << "Please entre the target student's name:" << '\n';
		cin.ignore();
		getline(cin, s);
		for (int i = 0; i < c1.size(); i++)
		{
			if (c1[i].first == s)
			{
				cout << c1[i].second << '\n' << '\n';
				goto a;
			}
		}
		cout << "Student isn’t assigned yet!" << '\n' << '\n';
		goto a;
	}
	case 5:
	{
		if (c1.empty())
		{
			cout << "No data to show" << '\n' << '\n';
			goto a;
		}
		else
		{
			for (int i = 0; i < c1.size() - 1; i++)
				for (int j = 0; j < c1.size() - i - 1; j++)
				{
					if (c1[j].second < c1[j + 1].second) swap(c1[j], c1[j + 1]);
					if (c1[j].second == c1[j + 1].second)
					{
						if (c1[j].first > c1[j + 1].first) swap(c1[j], c1[j + 1]);
					}
				}
			for (int i = 0; i < c1.size(); i++)
				cout << c1[i].first << '\t' << c1[i].second << '\n';
		}
		cout << '\n';
		goto a;
	}
	case 6: return 0;
	}
}
