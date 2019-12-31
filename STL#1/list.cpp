#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<list>
#include<cstdlib>
#include<ctime>

bool prim(int val) {
	bool p = true;
	if (val == 1)
		return false;
	else
		if (val >= 2) {
			int i = 2;
			while (p == true && i < (val / 2) + 2) {
				if (val % i == 0)
					p = false;
				++i;
			}
		}
	if (p == false)
		return false;
	else
		return true;

}

using namespace std;

int main() {
	list<int> list1{ 1,9,14,2,23,47,11,19,129,37 };
	list<int> list2{ 8,17,111,25,38,443,21 };
	list<int> list3;

	list1.sort();
	list2.sort();
	list3.merge(list1);
	list3.merge(list2);

	srand((int)time(0));

	for (int i = 0; i <= 100; ++i) {
		list3.push_back((rand() % 3500) + 35);
	}

	auto i = list3.begin();
	auto it = list3.begin();

	while (it != list3.end()) {
		i = it;
		++it;
		if (prim(*i) == false) {
			list3.erase(i);
		}
	}

	for (it = list3.begin(); it != list3.end(); ++it) {
		cout << *it << " ";
	}
	return 0;
}