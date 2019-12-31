#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<list>
#include<cstdlib>
#include<ctime>
#include<memory>
#include<set>
#include<limits>

using namespace std;

class Point 
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	int getX()
	{
		return this->x;
	}
	int getY() 
	{
		return this->y;
	}
	Point(Point& p)
	{
		p.x = this->x;
		p.y = this->y;
	}
	void print() 
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	Point &operator = (unique_ptr<Point>& p1) {
		this->x = p1->x;
		this->y = p1->y;
		return *this;
	}
	~Point() { };
};


class Rect
{
	Point p1, p2, p3, p4;
	int x1, x2, y1, y2;
	int width, length;
	int area;
	int perimeter;
	vector<int> allX, allY;
public:
	Rect(unique_ptr<Point> & p1, unique_ptr<Point> & p2, unique_ptr<Point> & p3, unique_ptr<Point> & p4) 
	{	
		x1 = 0;
		x2 = 0;
		y1 = 0;
		y2 = 0;
		
		this->p1 = p1;
		this->p2 = p1;
		this->p3 = p3;
		this->p4 = p4;

		set<int> setX, setY;

		setX.insert(p1->getX());
		setX.insert(p2->getX());
		setX.insert(p3->getX());
		setX.insert(p4->getX());

		setY.insert(p1->getY());
		setY.insert(p2->getY());
		setY.insert(p3->getY());
		setY.insert(p4->getY());

		set<int>::iterator it = setX.begin();

		x1 = *it;
		++it;
		x2 = *it;
		
		it = setY.begin();
		y1 = *it;
		++it;
		y2 = *it;


		width = abs(x1 - x2);
		length = abs(y1 - y2);

		allX.push_back(p1->getX());
		allX.push_back(p2->getX());
		allX.push_back(p3->getX());
		allX.push_back(p4->getX());

		allY.push_back(p1->getY());
		allY.push_back(p2->getY());
		allY.push_back(p3->getY());
		allY.push_back(p4->getY());

		sort(allX.begin(), allX.end());
		sort(allY.begin(), allY.end());
	}
	
	void print()
	{
		cout << "----Print Rect---\n";
		p1.print();
		p2.print();
		p3.print();
		p4.print();
		cout << "length = " << length << endl;
		cout << "width = " << width << endl;
	}		
	int getLength() 
	{
		return length;
	}
	int getWidth()
	{
		return width;
	}
	void setPerimeter(int p) 
	{
		perimeter = p;
	}
	void setArea(int a)
	{
		area = a;
	}
	int getMaxX()
	{
		return allX[allX.size() - 1];
	}
	int getMaxY()
	{
		return allY[allY.size() - 1];
	}
	int getMinX()
	{
		return allX[0];
	}
	int getMinY()
	{
		return allY[0];
	}
	~Rect() { };

	friend int perimeter(unique_ptr<Rect> const& r);
	friend int area(unique_ptr<Rect> const& r);
};

int perimeter(unique_ptr<Rect> const& r) {
	r->perimeter = 2 * (r->width + r->length);
	return r->perimeter;
}

int area(unique_ptr<Rect> const& r) {
	r->area = r->width * r->length;
	return r->area;
}

bool compare(const pair<int, int> & a, const pair<int, int> & b) {
	return a.first > b.first;
}

int main()
{
	//coordinates of first rectangle
	unique_ptr<Point> p1{ new Point(1, 1) };
	unique_ptr<Point> p2{ new Point(4, 1) };
	unique_ptr<Point> p3{ new Point(1, 5) };
	unique_ptr<Point> p4{ new Point(4, 5) };

	//coordinates of second rectangle....
	unique_ptr<Point> p5{ new Point(7, 2) };
	unique_ptr<Point> p6{ new Point(7, 6) };
	unique_ptr<Point> p7{ new Point(10, 2) };
	unique_ptr<Point> p8{ new Point(10, 6) };
	
	unique_ptr<Point> p9{ new Point(9, 12) };
	unique_ptr<Point> p10{ new Point(9, 3) };
	unique_ptr<Point> p11{ new Point(2, 12) };
	unique_ptr<Point> p12{ new Point(2, 3) };
	
	unique_ptr<Point> p13{ new Point(1, 9) };
	unique_ptr<Point> p14{ new Point(1, 15) };
	unique_ptr<Point> p15{ new Point(3, 15) };
	unique_ptr<Point> p16{ new Point(3, 9) };

	unique_ptr<Point> p17{ new Point(6, 7) };
	unique_ptr<Point> p18{ new Point(6, 14) };
	unique_ptr<Point> p19{ new Point(11, 7) };
	unique_ptr<Point> p20{ new Point(11, 14) };


	list <unique_ptr<Rect>> rectangles;
	// I will create 5 objects(Rectangle) based on obove coordinates
	
	
	unique_ptr<Rect> r1{ new Rect(p1, p2, p3, p4) };
	unique_ptr<Rect> r2{ new Rect(p5, p6, p7, p8) };
	unique_ptr<Rect> r3{ new Rect(p9, p10, p11, p12) };
	unique_ptr<Rect> r4{ new Rect(p13, p14, p15, p16) };
	unique_ptr<Rect> r5{ new Rect(p17, p18, p19, p20) };
	
	//-------------------**-----**----**--------------------//

	list<pair<int,int>> perimeterAndArea;

	//I calculated perimeter and area for every rectangle
	perimeterAndArea.push_back(make_pair(area(r1),perimeter(r1)));
	perimeterAndArea.push_back(make_pair(area(r2),perimeter(r2)));
	perimeterAndArea.push_back(make_pair(area(r3),perimeter(r3)));
	perimeterAndArea.push_back(make_pair(area(r4),perimeter(r4)));
	perimeterAndArea.push_back(make_pair(area(r5),perimeter(r5)));
	
	perimeterAndArea.sort(compare);
			
	list<pair<int, int>>::iterator it = perimeterAndArea.begin();

	int maxArea = it->first;
	int maxPerimeter = it->second;
	
	while (it != perimeterAndArea.end()) 
	{
		if (maxArea == it->first && maxPerimeter < it->second)
		{
	
			maxPerimeter = it->second;
		}
		++it;
	}

	cout << "Perimeter and area is:\n";
	for (auto i = perimeterAndArea.begin(); i != perimeterAndArea.end(); ++i)
	{
		cout << i->first << "  <----->  " << i->second << endl;
	}
	cout << "Rectangle with maximum area(and perimeter): " << maxArea << " <---> " << maxPerimeter << endl;
	
	int minX = numeric_limits<int>::max() , maxX = numeric_limits<int>::min(), minY = numeric_limits<int>::max(), maxY = numeric_limits<int>::min();


	rectangles.push_back(move(r1));
	rectangles.push_back(move(r2));
	rectangles.push_back(move(r3));
	rectangles.push_back(move(r4));
	rectangles.push_back(move(r5));

	for (auto i = rectangles.begin(); i != rectangles.end(); ++i) {
		if (maxX < (*i)->getMaxX())
		{
			maxX = (*i)->getMaxX();
		}
		if (maxY < (*i)->getMaxY())
		{
			maxY = (*i)->getMaxY();
		}
		if (minX > (*i)->getMinX()) 
		{
			minX = (*i)->getMinX();
		}
		if (minY > (*i)->getMinY()) 
		{
			minY = (*i)->getMinY();
		}
	}

	cout << "The coordinates of the rectangle where all objects are inscribed :\n";
	cout << "\n------------\n";
	cout << "Point 1\n";
	cout << "x = " << minX << "    " << "y = " << maxY << endl;

	cout << "\n------------\n";
	cout << "Point 2\n" ;
	cout << "x = " << maxX << "    " << "y = " << maxY << endl;

	cout << "\n------------\n";
	cout << "Point 3\n";
	cout << "x = " << minX << "    " << "y = " << minY << endl;
	
	cout << "\n------------\n";
	cout << "Point 4\n";
	cout << "x = " << maxX << "    " << "y = " << minY << endl;


	return 0;
}