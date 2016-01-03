#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int V, E;
		scanf("%d%d",&V,&E);
		printf("%d\n", E - V + 2);
	}
	return 0;
}