#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	char a[11][11];
	for(int i=0; i < N; i++)
		scanf("%s",a[i]);

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			char p,q;
			scanf(" %c%c",&p,&q);
			if(a[i][j] != p || p != q)
			{
				puts("Not Eyfa");
				return 0;
			}
		}
	}

	puts("Eyfa");
	return 0;
}