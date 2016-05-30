#include <bits/stdc++.h>

using namespace std;

int main()
{
	char P, Q;
	for(int tc=1; scanf(" %c %c", &P, &Q), P != '#'; tc++)
	{
		int N;
		scanf("%d ", &N);

		printf("Case %d\n", tc);

		char a[256];
		for(int i=0; i < N; i++)
		{
			gets(a);
			for(int j=0; a[j]; j++)
				if((a[j] | 32) == P || (a[j] | 32) == Q)
					putchar('_');
				else
					putchar(a[j]);
			puts("");
		}
		puts("");
	}
	return 0;
}