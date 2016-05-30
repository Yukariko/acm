#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		char O;
		scanf("%d %c", &N, &O);

		if(O == 'C')
		{
			for(int i=0; i < N; i++)
			{
				char C;
				scanf(" %c", &C);
				printf("%d ", C - 'A' + 1);
			}
		}
		else
		{
			for(int i=0; i < N; i++)
			{
				int n;
				scanf("%d", &n);
				printf("%c ", n + 'A' - 1);
			}
		}
		puts("");
	}
	return 0;
}