#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
	vector<int> group;
	DisjointSet(int N)
	{
		group.resize(N);
		for(int i=0; i < N; i++)
			group[i] = i;
	}

	int find(int n)
	{
		if(group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	void merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if(p != q)
			group[p] = q;
	}

	int group_num()
	{
		vector<bool> check(group.size(), false);
		int ans = 0;
		for(int i=0; i < group.size(); i++)
			if(check[find(i)] == false)
				check[find(i)] = true, ans++;
		return ans;
	}
};

int sq(int n)
{
	return n * n;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		DisjointSet djs(N);

		vector<int> X(N), Y(N), R(N);
		for(int i=0; i < N; i++)
			scanf("%d%d%d", &X[i], &Y[i], &R[i]);

		for(int i=0; i < N; i++)
			for(int j=i+1; j < N; j++)
				if(sq(X[i] - X[j]) + sq(Y[i] - Y[j]) <= sq(R[i] + R[j]))
					djs.merge(i, j);

		printf("%d\n", djs.group_num());
	}
	return 0;
}