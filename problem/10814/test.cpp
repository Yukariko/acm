#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	string a[100001];
	vector<int> p[201];

	cin >> N;
	for(int i=0; i < N; i++)
	{
		int age;
		cin >> age >> a[i];
		p[age].push_back(i);
	}

	for(int i=1; i <= 200; i++)
	{
		if(p[i].size())
		{
			sort(p[i].begin(), p[i].end());
			for(vector<int>::iterator it = p[i].begin(); it != p[i].end(); ++it)
				printf("%d %s\n",i, a[*it].c_str());
		}
	}
	return 0;
}