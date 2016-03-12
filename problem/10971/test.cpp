#include <bits/stdc++.h>

using namespace std;

int N;
int a[11][11];
bool visit[11];
int start;


int solve(int pos, int here)
{
	if(pos == N)
		return a[here][start]? a[here][start]: 9876354321;
		
	int ans = 987654321;
	for(int there=0; there < N; there++)
	{
		if(visit[there] == false && a[here][there])
		{
			visit[there] = true;
			ans = min(ans, a[here][there] + solve(pos + 1, there));
			visit[there] = false;
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);
	
	int ans = 987654321;
	while(start < N)
	{
		visit[start] = true;
		ans = min(ans, solve(1, start));
		visit[start] = false;
		start++;
	}
	printf("%d", ans);
	return 0;
}
