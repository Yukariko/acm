#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<pair<int,int>> a(3);
	for(int i=0; i < 3; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	int s = (a[1].first - a[0].first) * (a[2].second - a[0].second) -
					(a[1].second - a[0].second) * (a[2].first - a[0].first);

	printf("%d", s > 0? 1: s < 0? -1 : 0);
	return 0;
}