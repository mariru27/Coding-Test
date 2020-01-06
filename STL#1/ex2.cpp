#include<iostream>
#include<fstream>
#include<vector>
#include<memory>

using namespace std;

int minDif = INT_MAX;
int solution = -1;

int binarySearch(vector<int> v, int val, int a = 0,int b = 1)
{
	if (a <= b)
	{
		int mid = a + (b - a) / 2;
		if (minDif > abs(v[mid] - val))
		{
			minDif = abs(v[mid] - val);
			solution = v[mid];
		}
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
	vector<int> v{ 2,5,6,7,8,8,9 };
	binarySearch(v, 11, 0, 6);
	cout << solution;
	return 0;
}