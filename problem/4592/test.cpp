#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while(scanf("%d", &N), N)
	{
		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		printf("%d ", a[0]);
		for(int i=1; i < N; i++)
			if(a[i-1] != a[i])
				printf("%d ", a[i]);
		puts("$");
	}
	return 0;
}