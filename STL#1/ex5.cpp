#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<deque>

using namespace std;

int main()
{
	int i = 0;
	int isUp = 0;
	deque<string> books;
	
	books.push_back("book1");
	books.push_back("book2");
	books.push_back("book3");
	books.push_back("book4");
	books.push_back("book5");
	books.push_back("book6");

	int act = 1;
	int n = 5;

	while (i < n)
	{
		cout << "action(write 1 or -1): ";
		cin >> act;
		
		if (act != -1)
		{
			string book;
			cout << "\nwrite a name of a book : ";
			cin >> book;
			
			if (isUp == 0)
			{
				books.push_back(book);
			}
			else
			{
				books.push_front(book);
			}
		}
		else
		{
			isUp = 1 - isUp;
		}
		++i;
	}

	if (isUp == 0)
	{
		for (auto it = books.begin(); it != books.end(); ++it)
		{
			cout << *it << " ";
		}
	}
	else
	{
		reverse(books.begin(), books.end());
		for (auto it = books.begin(); it != books.end(); ++it)
		{
			cout << *it << " ";
		}
	}

	return 0;
}