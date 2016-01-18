#include <bits/stdc++.h>

using namespace std;

struct DisjointSet
{
	vector<int> group;
	vector<long long> diff;
	
	DisjointSet(int N)
	{
		group.resize(N+1);
		for(int i=1; i <= N; i++)
			group[i] = i;

		diff.resize(N+1);
		fill(diff.begin(), diff.end(), 0);
	}

	int find(int n)
	{
		if(group[n] == n)
			return n;
		int parent = group[n];
		group[n] = find(parent);
		diff[n] = diff[n] + diff[parent];
		return group[n];
	}

	void merge(int p, int q, int w)
	{
		int np = find(p);
		int nq = find(q);
		if(np != nq)
		{
			group[np] = nq;
			diff[np] = diff[q] + w - diff[p];
			find(p);
		}
	}
};

int main()
{
	int N, M;
	while(scanf("%d%d", &N, &M), N)
	{
		DisjointSet djs(N);
		for(int i=0; i < M; i++)
		{
			char cmd;
			scanf(" %c", &cmd);
			if(cmd == '!')
			{
				int p, q, w;
				scanf("%d%d%d", &p, &q, &w);
				djs.merge(p, q, w);
			}
			else
			{
				int p, q;
				scanf("%d%d", &p, &q);
				int np = djs.find(p), nq = djs.find(q);
				if(np != nq)
					puts("UNKNOWN");
				else
					printf("%lld\n", djs.diff[p] - djs.diff[q]);
			}
		}
	}
	return 0;
}