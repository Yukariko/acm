#include <bits/stdc++.h>

using namespace std;

int H, W;
int N, M;
int S;

int a[1001];

int nextPos[1000001];

int solve(int pos, int cnt)
{
	if(pos == M && cnt >= 0)
		return true;
	if(cnt <= 0)
		return false;

	if(a[pos] + S > W)
	{
		return true;
	}

	return solve(nextPos[a[pos]+S],cnt-1);
}

int main()
{
	scanf("%d%d", &H, &W);
	scanf("%d%d", &N, &M);

	int left = 0, right = min(H, W);
	for(int i=0; i < M; i++)
	{
		int y, x;
		scanf("%d%d", &y, &x);
		a[i] = x;
		left = max(left, y);
	}

	sort(a, a + M);

	int spos = 0;
	for(int i=0; i < M; i++)
	{
		while(spos <= a[i])
		{
			nextPos[spos] = i;
			spos++;
		}
	}

	while(spos <= W)
	{
		nextPos[spos] = M;
		spos++;
	}

	while(left <= right)
	{
		int mid = (left + right) / 2;
		S = mid;
		if(solve(0, N) == 1)
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d", left);
	return 0;
}