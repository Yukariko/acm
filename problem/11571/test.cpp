#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int P, Q;
		scanf("%d%d", &P, &Q);

		printf("%d.", P / Q);

		char a[1025];

		int check[1024];
		memset(check, -1, sizeof(check));

		int m = P % Q;
		int idx = 0;
		while(check[m] == -1)
		{
			check[m] = idx;
			m *= 10;
			a[idx] = (m / Q) + '0';
			m %= Q;
			idx++;
		}

		int cycle = check[m];
		for(int i=0; i < idx; i++)
		{
			if(i == cycle)
				putchar('(');
			putchar(a[i]);
		}
		puts(")");
	}
	return 0;
}