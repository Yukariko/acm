#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);
		if(N < 4)
			printf("%d\n", 1 << N);
		else if(N == 4)
			printf("20\n");
		else
			printf("frogger\n");
	}
	return 0;
}