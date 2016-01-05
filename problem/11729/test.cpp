#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int u, int v)
{
	if(n == 1)
	{
		printf("%d %d\n", u, v);

	}
	else
	{
		int etc = 6 - u - v;
		hanoi(n-1, u, etc);
		printf("%d %d\n", u, v);
		hanoi(n-1, etc, v);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	printf("%d\n", (1 << N) - 1);
	hanoi(N, 1, 3);
	return 0;
}