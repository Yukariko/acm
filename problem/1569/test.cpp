#include <bits/stdc++.h>

using namespace std;

int check(const vector<pair<int,int>>& a, int sx, int sy, int L)
{
	int N = a.size();
	for(int i=0; i < N; i++)
	{
		if(a[i].first < sx || a[i].first > sx + L || a[i].second < sy || a[i].second > sy + L)
			return false;
		else if(a[i].first != sx && a[i].first != sx + L && a[i].second != sy && a[i].second != sy + L)
			return false;
	}
	return true;
}

int main()
{
	int N;
	scanf("%d",&N);
	if(N == 1)
		return puts("-1"), 0;

	vector<pair<int,int>> a(N);
	int maxX = -1001, minX = 1001, maxY = -1001, minY = 1001;
	for(int i=0; i < N; i++)
	{
		scanf("%d%d",&a[i].first, &a[i].second);
		maxX = max(maxX, a[i].first);
		minX = min(minX, a[i].first);
		maxY = max(maxY, a[i].second);
		minY = min(minY, a[i].second);
	}

	int L = max(maxX - minX, maxY - minY);
	for(int i=0; i < N; i++)
	{
		int sx = a[i].first;
		int sy = a[i].second;

		for(int i=0; i <= L; i++)
		{
			if(check(a, sx - i, sy, L) || check(a, sx, sy - i, L))
			{
				printf("%d", L);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}