#include <bits/stdc++.h>

using namespace std;

struct DisjointSet
{
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
		if(group[p] != group[q])
			group[q] = p;
	}
	
	int countGroup()
	{
		vector<bool> visit(group.size(), false);
		int ans = 0;
		for(size_t i=1; i < group.size(); i++)
			if(visit[find(i)] == false)
				visit[find(i)] = true, ans++;
		return ans;
	}
};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	DisjointSet djs(N+1);
	
	vector<vector<int>> enemy(N+1);
	vector<bool> visit(N+1, false);

	while(M--)
	{
		char c;
		int p, q;
		scanf(" %c%d%d", &c, &p, &q);
		if(c == 'F')
			djs.merge(p, q);
		else
		{
			enemy[p].push_back(q);
			enemy[q].push_back(p);
			visit[p] = visit[q] = true;
		}
	}

	for(int i=1; i <= N; i++)
	{
		if(!visit[i])
			continue;

		for(size_t j=0; j < enemy[i].size(); j++)
			for(size_t k=j+1; k < enemy[i].size(); k++)
				djs.merge(enemy[i][j], enemy[i][k]);
	}
	
	printf("%d", djs.countGroup());
	return 0;
}