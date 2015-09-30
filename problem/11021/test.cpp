#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	for(int tc=1; tc <= T; tc++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n", tc, a+b);
	}
	return 0;
}