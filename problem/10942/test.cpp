#include <bits/stdc++.h>

using namespace std;

int cache[2001][2001];

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			if(i - j < 0 || i + j >= N || a[i-j] != a[i+j])
				break;
			cache[i-j][i+j] = 1;
		}
	}

	for(int i=1; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			if(i - j - 1 < 0 || i + j >= N || a[i-j-1] != a[i+j])
				break;
			cache[i-j-1][i+j] = 1;
		}
	}

	int M;
	scanf("%d", &M);

	while(M--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		printf("%d\n", cache[l][r]);
	}
	return 0;
}