#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

bool cmp(const pair<int,int>& p, const pair<int,int>& q)
{
	return p.second < q.second;
}

int main()
{
	int N;
	cin >> N;

	vector< pair<int,int> > a(N);
	for(int i=0; i < N; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	long long ans = 0;
	bool equals = false;
	for(int i=1; i < N; i++)
	{
		if(a[i].first == a[i-1].first)
			equals = true;
		else if(equals)
		{
			ans++;
			equals = false;
		}
			
	}
	if(equals)
		ans++;

	sort(a.begin(), a.end(), cmp);

	equals = false;
	for(int i=1; i < N; i++)
	{
		if(a[i].second == a[i-1].second)
			equals = true;
		else if(equals)
		{
			ans++;
			equals = false;
		}
	}
	if(equals)
		ans++;
	cout << ans;
	return 0;
}