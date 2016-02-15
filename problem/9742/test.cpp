#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[16];
	int N;
	while(~scanf("%s%d",a, &N))
	{
		printf("%s %d = ", a, N);

		int len = strlen(a);
		while(--N)
			if(!next_permutation(a, a + len))
				break;

		if(N)
			puts("No permutation");
		else
			puts(a);
	}
	return 0;
}