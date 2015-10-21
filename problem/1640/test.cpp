#include <bits/stdc++.h>

using namespace std;

int N, M;
char a[1001][1001];

int main()
{
	scanf("%d%d ",&N,&M);
	for(int i=0; i < N; i++)
		scanf("%s",a[i]);

	int p=0,q=0,r=0,s=0;
	for(int i=0; i < N; i++)
	{
		int pick = 0;
		for(int j=0; j < M; j++)
			pick += a[i][j] == '1';
		if(pick % 2 == 0)
			p++;
		else
			q++;
	}

	for(int i=0; i < M; i++)
	{
		int pick = 0;
		for(int j=0; j < N; j++)
			pick += a[j][i] == '1';
		if(pick % 2 == 0)
			r++;
		else
			s++;
	}

	int ans = N*M;
	if(q % 2 == 0)
		ans = min(p+r, q+s);
	else
		ans = min(p+s, q+r);
	printf("%d",ans);
	return 0;
}