#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N, C;
		scanf("%d%d",&N,&C);
		printf("%d\n",(N + C - 1) / C);
	}
	return 0;
}