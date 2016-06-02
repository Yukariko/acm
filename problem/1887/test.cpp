#include <bits/stdc++.h>

using namespace std;

int T, N;
int a[52];

int solve(int pos, int mask)
{
	if(pos == T)
	{
		for(int i=0; i < N; i++)
			if((mask & a[i]) == a[i])
				return 0;
		return 1;
	}

	return solve(pos + 1, mask) + solve(pos + 1, mask | (1 << pos));
}

int main()
{
	
	scanf("%d%d", &T, &N);

	for(int i=0; i < N; i++)
	{
		int l;
		scanf("%d", &l);

		while(l--)
		{
			int n;
			scanf("%d", &n);
			n--;
			a[i] |= 1 << n;
		}
	}

	printf("%d", solve(0, 0));
	return 0;
}