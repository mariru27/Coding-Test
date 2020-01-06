#include<iostream>
#include<fstream>
#include<vector>
#include<memory>

using namespace std;


int binarySearch(vector<int> v, int val, int a = 0,int b = 1)
{
	if (a <= b)
	{
		int mid = a + (b - a) / 2;
		if (v[mid] == val)
			return mid;
		if (val < v[mid])
			return binarySearch(v, val, a, mid - 1);
		return binarySearch(v, val, mid + 1, b);
	}
	return -1;
}


int main()
{
	vector<int> v{ 8,9,10,3,4,5,6,7 };
	int value, prevVal = v[0];
	bool ordered = false;
	auto it = v.begin();

	while (ordered == false)
	{
		if (ordered == false)
		{
			value = *it;
			it = v.erase(it);
			v.push_back(value);
		}
		if ( prevVal > *it)
		{
			ordered = true;
		}
		prevVal = *it;
	}
	cout << " The element " << 5 <<" is on position : " << binarySearch(v, 5,0,v.size() - 1);

	return 0;
}