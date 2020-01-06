#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<unordered_map>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

class Rectangle
{
	int width;
	int height;
	int x1, y1;
public:
	Rectangle(int x1, int y1, int w, int h) : x1(x1), y1(y1), width(w), height(h) { };
	bool isInside(int x, int y)
	{
		if (x - x1 <= width && x - x1 >= 0 && y - y1 >= 0 && y - y1 <= height)
			return true;
		else
			return false;
	}
};


int main()
{
	ifstream in;
	ofstream out;
	in.open("ograzi.in");
	int n, m, w, h;
	vector<Rectangle> rectangles;

	in >> n >> m >> w >> h;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		in >> x >> y;
		rectangles.push_back(Rectangle(x, y, w, h));
	}

	int counter = 0;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		in >> x >> y;

		for (auto j = rectangles.begin(); j != rectangles.end(); ++j)
		{
			if (j->isInside(x, y) == true)
			{
				++counter;
				break;
			}
		}
	}

	cout << counter;

	in.close();
	return 0;
}