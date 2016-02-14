#include <bits/stdc++.h>

using namespace std;

int check[1001];
bool adj[1001][1001];
vector<int> topology[1001];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for(int i=0; i < M; i++)
	{
		int len;
		scanf("%d", &len);

		vector<int> a(len);
		for(int j=0; j < len; j++)
			scanf("%d", &a[j]);

		for(int j=0; j < len-1; j++)
		{
			for(int k=j+1; k < len; k++)
			{
				if(adj[a[j]][a[k]])
					continue;

				adj[a[j]][a[k]] = true;
				check[a[k]]++;
				topology[a[j]].push_back(a[k]);
			}
		}
	}

	queue<int> q;
	for(int i=1; i <= N; i++)
		if(check[i] == false)
			q.push(i);

	queue<int> ans;

	while(!q.empty())
	{
		int here = q.front();
		q.pop();

		ans.push(here);

		for(size_t i=0; i < topology[here].size(); i++)
		{
			int there = topology[here][i];
			if(check[there])
			{
				check[there]--;
				if(check[there] == 0)
					q.push(there);
			}
		}
	}

	if(ans.size() != N)
	{
		puts("0");
		return 0;
	}

	while(!ans.empty())
	{
		printf("%d\n", ans.front());
		ans.pop();
	}

	return 0;
}