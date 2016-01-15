#include <bits/stdc++.h>

using namespace std;

int a[2188][2188];
int ans[3];

void solve(int y, int x, int count)
{
	if(count == 1)
	{
		ans[a[y][x]+1]++;
		return;
	}

	
	bool eq = true;

	for(int i=0; i < count; i++)
	{
		for(int j=0; j < count; j++)
		{
			if(a[y][x] != a[y + i][x + j])
			{
				eq = false;
				break;
			}
		}
		if(eq == false)
			break;
	}

	if(eq)
		ans[a[y][x]+1]++;
	else
	{
		count /= 3;
		for(int i=0; i < 3; i++)
			for(int j=0; j < 3; j++)
				solve(y + i * count, x + j * count, count);
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);

	solve(0, 0, N);
	for(int i=0; i < 3; i++)
		printf("%d\n", ans[i]);
	return 0;
}