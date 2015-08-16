#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int,int>& p,const pair<int,int>& q)
{
	if(p.first != q.first)
		return p.first > q.first;
	return p.second < q.second;
}

int main()
{
	int N;
	cin >> N;

	int a[N][5];
	for(int i=0; i < N; i++)
		for(int j=0; j < 5; j++)
			cin >> a[i][j];

	bool friends[1001][1001]={};

	vector<int> sameClass[5][10];

	for(int i=0; i < N; i++)
		for(int j=0; j < 5; j++)
			sameClass[j][a[i][j]].push_back(i);


	for(int i=0; i < 5; i++)
	{
		for(int j=1; j <= 9; j++)
		{
			vector<int>& current = sameClass[i][j];

			for(int p=0; p < current.size(); p++)
				for(int q=p+1; q < current.size(); q++)
					friends[current[p]][current[q]] = friends[current[q]][current[p]] = true;
		}
	}

	vector< pair<int,int> > v(N);

	for(int i=0; i < N; i++)
	{
		v[i].second = i+1;
		v[i].first = 0;
		for(int j=0; j < N; j++)
			if(friends[i][j])
				v[i].first++;
	}

	sort(v.begin(), v.end(), cmp);

	cout << v[0].second;
	return 0;
}