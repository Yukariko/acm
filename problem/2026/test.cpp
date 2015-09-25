#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int K, N, F;
bool friends[901][901];
vector<int> friendSet[901];

int pick[63];
bool visit[901];

void solve(int npick, int pos)
{
	if(npick == K)
	{
		for(int i=0; i < K; i++)
			printf("%d\n", pick[i]);
		exit(0);
	}

	for(size_t i=0; i < friendSet[pos].size(); i++)
	{
		int now_friend = friendSet[pos][i];
		if(visit[now_friend])
			continue;

		bool find = true;
		for(int j=0; j < npick; j++)
		{
			if(!friends[pick[j]][now_friend])
			{
				find = false;
				break;
			}
		}

		if(find)
		{
			pick[npick] = now_friend;
			visit[now_friend] = true;
			solve(npick+1, now_friend);
			visit[now_friend] = false;
		}
	}
}

int main()
{
	scanf("%d%d%d",&K,&N,&F);
	for(int i=0; i < F; i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		friends[x][y] = friends[y][x] = true;
		friendSet[x].push_back(y);
		friendSet[y].push_back(x);
	}

	for(int i=1; i <= N; i++)
	{
		if(friendSet[i].size() < K-1)
			visit[i] = true;
		else
			sort(friendSet[i].begin(), friendSet[i].end());
	}

	for(int i=1; i <= N; i++)
	{
		if(visit[i])
			continue;
		pick[0] = i;
		visit[i] = true;
		solve(1, i);
		visit[i] = false;
	}

	printf("-1");
	return 0;
}