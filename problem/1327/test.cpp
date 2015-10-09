#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K;
bool visit[87654322];

int reverse(int n, int pos)
{
	char a[10];
	sprintf(a, "%d", n);
	reverse(a+pos, a+pos+K);
	return atoi(a);
}

int solve(int n)
{
	int fin = 0;
	for(int i=1; i <= N; i++)
	{
		fin *= 10;
		fin += i;
	}

	queue<int> bfs;
	bfs.push(n);
	visit[n] = true;

	int ans = 0;
	while(!bfs.empty())
	{
		size_t size = bfs.size();
		for(int i=0; i < size; i++)
		{
			int pick = bfs.front();
			bfs.pop();
			if(pick == fin)
				return ans;

			for(int i=0; i + K <= N; i++)
			{
				int next = reverse(pick, i);
				if(!visit[next])
				{
					visit[next] = true;
					bfs.push(next);
				}
			}
		}
		ans++;
	}
	return -1;
}

int main()
{
	scanf("%d%d",&N,&K);
	int n = 0;
	for(int i=0; i < N; i++)
	{
		int num;
		scanf("%d",&num);
		n *= 10;
		n += num;
	}
	printf("%d", solve(n));
	return 0;
}