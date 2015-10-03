#include <bits/stdc++.h>

using namespace std;

int N;
int a[1001];
int cache[1001][1001];
int sel[1001][1001];

int solve(int left, int right)
{
	if(left == right)
		return a[left];

	int& ret = cache[left][right];
	if(ret != -987654321)
		return ret;

	int& choose = sel[left][right];
	choose = 0;

	int l = a[left] - solve(left+1,right);
	if(ret < l)
	{
		choose = 1;
		ret = l;
	}
	
	int r = a[right] - solve(left,right-1);
	if(ret < r)
	{
		choose = 2;
		ret = r;
	}
	return ret;
}

int answer(int left, int right, int turn)
{
	if(left == right)
		return turn == 0? a[left]: 0;

	if(sel[left][right] == 1)
		return (turn == 0? a[left]: 0) + answer(left+1, right, !turn);
	return (turn == 0? a[right]: 0) + answer(left, right-1, !turn);
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=0; i < N; i++)
			scanf("%d",&a[i]);

		for(int i=0; i < N; i++)
			for(int j=i; j < N; j++)
				cache[i][j] = -987654321;

		solve(0, N-1);
		printf("%d\n", answer(0, N-1, 0));
	}
	return 0;
}