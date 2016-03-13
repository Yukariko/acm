#include <bits/stdc++.h>

using namespace std;

int sq(int n)
{
	return n * n;
}

int main()
{
	vector<pair<int, pair<int, int>>> a(16);
	for(int i=0; i < 16; i++)
		scanf("%d%d%d", &a[i].first, &a[i].second.first, &a[i].second.second);	

	int R, G, B;
	while(scanf("%d%d%d", &R, &G, &B), R != -1)
	{
		int d = 987654321;
		int sel = 0;
		for(int i=0; i < 16; i++)
		{
			int dist = sq(a[i].first - R) + sq(a[i].second.first - G) + sq(a[i].second.second - B);
			if(dist < d)
			{
				d = dist;
				sel = i;
			}
		}

		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", R, G, B, a[sel].first, a[sel].second.first, a[sel].second.second);
	}
	return 0;
}