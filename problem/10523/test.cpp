#include <bits/stdc++.h>

using namespace std;

int ccw(pair<int, int> a, pair<int, int> b)
{
	return a.first * b.second - a.second * b.first;
}

int ccw(pair<int, int> p, pair<int, int> a, pair<int, int> b)
{
	return ccw(make_pair(a.first - p.first, a.second - p.second),make_pair(b.first - p.first, b.second - p.second));
}

int main()
{
	int N, P;
	scanf("%d%d",&N,&P);

	if(N == 1)
	{
		puts("possible");
		return 0;
	}

	vector< pair<int, int> > a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d",&a[i].first, &a[i].second);

	for(int tc=0; tc < 250; tc++)
	{
		int p = 0, q = 0;
		while(p == q)
		{
			p = rand() % N;
			q = rand() % N;
		}

		if(a[p] > a[q])
			swap(p, q);

		int ans = 2;
		for(int i=0; i < N; i++)
		{
			if(i == p || i == q)
				continue;

			if(ccw(a[i],a[p],a[q]) == 0)
				ans++;
		}


		if(ans * 100 >= P * N)
		{
			printf("possible");
			return 0;
		}
	}
	printf("impossible");
	return 0;
}