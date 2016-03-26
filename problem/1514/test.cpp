#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
char a[101];
char b[101];

int rot(int n, int p)
{
	return (n + p + 100) % 10;
}

int cache2[10][10][10][10];
int minRot(int g, int gp, int gq, int gr)
{
	int& dist = cache2[g][gp][gq][gr];
	if(dist != -1)
		return dist;

	bool visit[10][10][10] = {};
	queue<int> bfs;
	visit[gp][0][0] = true;
	bfs.push(gp * 100);

	dist = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int p = bfs.front() / 100;
			int q = bfs.front() % 100 / 10;
			int r = bfs.front() % 10;
			bfs.pop();

			if(p == g && q == gq && r == gr)
				return dist;

			for(int i=-3; i <= 3; i++)
			{
				if(!visit[rot(p, i)][q][r])
				{
					visit[rot(p, i)][q][r] = true;	
					bfs.push(rot(p, i) * 100 + q * 10 + r);
				}
				if(!visit[rot(p, i)][rot(q, i)][r])
				{
					visit[rot(p, i)][rot(q, i)][r] = true;
					bfs.push(rot(p, i) * 100 + rot(q, i) * 10 + r);
				}
				if(!visit[rot(p, i)][rot(q, i)][rot(r, i)])
				{
					visit[rot(p, i)][rot(q, i)][rot(r, i)] = true;
					bfs.push(rot(p, i) * 100 + rot(q, i) * 10 + rot(r, i));
				}
			}
		}
		dist++;
	}
	return dist = -1;
}

int cache[101][10][10];
int solve(int pos, int curRot, int nextRot)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos][curRot][nextRot];
	if(ans != -1)
		return ans;
	
	int cur = rot(a[pos], curRot);

	ans = INF;
	for(int i=0; i < 10; i++)
	{
		for(int j=0; j < 10; j++)
		{
			int rotate = minRot(b[pos], cur, i, j);
			ans = min(ans, rotate + solve(pos + 1, rot(nextRot, i), j));
		}
	}
	return ans;
}
int main()
{
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	scanf("%d%s%s", &N, a, b);
	for(int i=0; i < N; i++)
		a[i] -= '0', b[i] -= '0';

	printf("%d", solve(0, 0, 0));
	return 0;
}