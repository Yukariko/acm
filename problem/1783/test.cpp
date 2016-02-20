#include <bits/stdc++.h>

using namespace std;

const int moveable[] = {0, 1, 2, 2, 3, 3};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	if(N == 1)
	{
		puts("1");
		return 0;
	}

	if(N == 2)
	{
		if(M <= 7)
			printf("%d", (M - 1) / 2 + 1);
		else
			printf("4");
		return 0;
	}

	if(M <= 4)
	{
		printf("%d", M);
		return 0;
	}

	if(M <= 6)
	{
		printf("%d", 4);
		return 0;
	}

	int ans = 5;
	M -= 7;
	ans += M;
	printf("%d", ans);
	return 0;
}