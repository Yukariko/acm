#include <bits/stdc++.h>

using namespace std;

int N;
int a[10001];
int ans[2][2];

int get_idx(int pos, int idx)
{
	if(pos == 0)
		return a[idx];
	if(ans[0][0] <= idx && idx <= ans[0][1])
		return a[ans[0][1] - (idx - ans[0][0])];
	return a[idx];
}

void solve(int pos)
{
	int error = -1;
	for(int i=1; i <= N; i++)
	{
		if(get_idx(pos, i) != i)
		{
			error = i;
			break;
		}
	}

	if(error == -1)
	{
		for(int i=0; i < pos; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
		for(int i=pos; i < 2; i++)
			printf("1 1\n");
		exit(0);
	}

	if(pos == 1)
	{
		int left = error;
		while(error < N && get_idx(pos, error) - 1 == get_idx(pos, error+1))
			error++;

		int right = error;

		error++;
		while(error <= N && get_idx(pos, error) == error)
			error++;

		if(error > N)
		{
			ans[pos][0] = left, ans[pos][1] = right;
			for(int i=0; i < 2; i++)
				printf("%d %d\n", ans[i][0], ans[i][1]);
			exit(0);
		}
		return;
	}

	for(int i=1; i <= N; i++)
	{
		int next = a[i];
		int left = i, right = a[i];
		if(left > right)
			swap(left, right);

		ans[pos][0] = left, ans[pos][1] = right;
		solve(pos+1);
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1; i <= N; i++)
		scanf("%d",&a[i]);

	solve(0);
	return 0;
}