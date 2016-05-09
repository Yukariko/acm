#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int D, N, S, P;
		scanf("%d%d%d%d", &D, &N, &S, &P);

		int ans = S * N - (P * N + D);
		if(ans < 0)
			puts("do not parallelize");
		else if(ans == 0)
			puts("does not matter");
		else
			puts("parallelize");
	}
	return 0;
}