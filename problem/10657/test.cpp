#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector< pair<int,int> > a(N);
	for(int i=0; i < N; i++)
		cin >> a[i].first >> a[i].second;


	int ans = 1;
	int speed = a[N-1].second;
	for(int i=N-2; i >= 0; i--)
	{
		if(a[i].second <= speed)
		{
			ans++;
			speed = a[i].second;
		}
	}

	cout << ans;
	return 0;
}