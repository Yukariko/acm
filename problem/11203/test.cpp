#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	char a[31];
	scanf("%d%s", &N, a);

	int R = 1;
	for (int i=0; a[i]; ++i)
	{
		R *= 2;
		if(a[i] == 'R')
			R += 1;
	}
	printf("%d", (1 << (N+1)) - R);
	return 0;
}