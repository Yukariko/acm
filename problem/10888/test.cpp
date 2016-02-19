#include <bits/stdc++.h>

using namespace std;

long long calcPassedIsland(int N)
{
	return 1LL * N * (N - 1) / 2;
}

long long calcBridgeCount(int N)
{
	return 1LL * N * (N + 1) * (N - 1) / 6;
}

struct DisjointSet {
	vector<int> group;
	vector<int> count;

	long long passable = 0;
	long long bridge = 0;

	DisjointSet(int N)
	{
		group.resize(N);
		for(int i=0; i < N; i++)
			group[i] = i;

		count.resize(N, 1);
	}

	int find(int n)
	{
		if(group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	int merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if(p != q)
		{
			group[p] = q;

			passable -= calcPassedIsland(count[p]);
			passable -= calcPassedIsland(count[q]);
			bridge -= calcBridgeCount(count[p]);
			bridge -= calcBridgeCount(count[q]);
			count[q] += count[p];
			passable += calcPassedIsland(count[q]);
			bridge += calcBridgeCount(count[q]);

		}

		printf("%lld %lld\n", passable, bridge);
		return count[q];
	}
};

int main()
{
	int N;
	scanf("%d", &N);

	DisjointSet djs(N);

	for(int i=1; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		n--;
		djs.merge(n, n+1);
	}
	return 0;
}