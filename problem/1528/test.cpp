// bfs, shom
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> a;

void makeShom(int n)
{
	int p = n * 10 + 4;
	int q = n * 10 + 7;
	if(p <= N)
	{
		a.push_back(p);
		makeShom(p);
	}
	if(q <= N)
	{
		a.push_back(q);
		makeShom(q);
	}
}

int main()
{
	scanf("%d", &N);
	makeShom(0);
	sort(a.begin(), a.end());

	vector<int> parent(N+1, -1);

	queue<int> bfs;
	bfs.push(0);

	while(!bfs.empty())
	{
		int here = bfs.front();
		bfs.pop();

		if(here == N)
			break;

		for(size_t i=0; i < a.size(); i++)
		{
			int there = here + a[i];
			if(there <= N && parent[there] == -1)
			{
				parent[there] = here;
				bfs.push(there);
			}
		}
	}

	if(parent[N] == -1)
		puts("-1");
	else
	{
		vector<int> ans;
		int pos = N;
		while(parent[pos] != -1)
		{
			ans.push_back(pos - parent[pos]);
			pos = parent[pos];
		}

		reverse(ans.begin(), ans.end());
		for(size_t i=0; i < ans.size(); i++)
			printf("%d ", ans[i]);
	}
	return 0;
}