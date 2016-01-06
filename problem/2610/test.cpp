#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int disjointSet[101];

int find(int n)
{
	if(n==disjointSet[n])return n;
	return disjointSet[n]=find(disjointSet[n]);
}

void merge(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x != y)
		disjointSet[x] = y;
}

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	int a[101][101];
	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			a[i][j] = INF;
		a[i][i] = 0;
	}

	while(M--)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		a[u][v] = a[v][u] = 1;
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			for(int j=1; j <= N; j++)
				if(a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];

	for(int i=1; i <= N; i++)
		disjointSet[i] = i;

	for(int i=1; i <= N; i++)
		for(int j=1; j <= N; j++)
			if(i != j && a[i][j] != INF)
				merge(i, j);

	map<int, vector<int>> group;
	for(int i=1; i <= N; i++)
		group[find(i)].push_back(i);

	vector<int> ans;
	for(auto &pick : group)
	{
		vector<int>& member = pick.second;

		int representDist = INF;
		int represent;
		for(size_t i=0; i < member.size(); i++)
		{
			int maxDist = 0;
			for(size_t j=0; j < member.size(); j++)
				if(a[member[i]][member[maxDist]] < a[member[i]][member[j]])
					maxDist = j;

			if(representDist > a[member[i]][member[maxDist]])
			{
				representDist = a[member[i]][member[maxDist]];
				represent = member[i];
			}
		}

		ans.push_back(represent);
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());
	for(size_t i=0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}