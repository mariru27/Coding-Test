#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<unordered_map>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("companies.in");

	unordered_map<string, string> companies;
	set<string> allCompanies;
	string company1, company2;

	while (in >> company1 >> company2)
	{
		companies[company1] = company2;
		allCompanies.insert(company1);
		allCompanies.insert(company2);
	}

	vector<string> maximChain;
	vector<string> chain;

	for (auto it = allCompanies.begin(); it != allCompanies.end(); ++it)\
	{
		string rememberCompany = *it;

		while (true)
		{
			if (rememberCompany == "")
			{
				if (chain.size() > maximChain.size())
				{
					maximChain = chain;
				}
				break;
			}
			chain.push_back(rememberCompany);
			rememberCompany = companies[rememberCompany];
			if (find(chain.begin(), chain.end(), rememberCompany ) != chain.end() )
			{
				break;
			}
			
		}
		chain.clear();
	}

	for (auto it = maximChain.begin(); it != maximChain.end(); ++it)
	{
		cout << *it << " ";
	}

	in.close();
	return 0;
}