#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int p, q;
		scanf("%d%d",&p,&q);

		printf("You get %d piece(s) and your dad gets %d piece(s).\n", p / q, p % q);
	}
	return 0;
}