#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
	vector<int> group;
	vector<int> save;
	DisjointSet(int N)
	{
		group.resize(N);
		for(int i=0; i < N; i++)
			group[i] = i;

		save.resize(N, 1);
	}

	int find(int n)
	{
		if(group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	bool merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if(p != q)
		{
			if(save[q] + save[p] == 0)
				return false;
			group[p] = q;
			save[q] = save[q] - 1 + save[p];
		}
		else
		{
			if(save[p] == 0)
				return false;
			save[p]--;
		}

		return true;
	}
};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	DisjointSet djs(M+1);

	while(N--)
	{
		int p, q;
		scanf("%d%d", &p, &q);

		if(djs.merge(p, q))
			puts("LADICA");
		else
			puts("SMECE");
	}
	return 0;
}