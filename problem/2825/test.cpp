#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int check[1024] = {};

	for(int i=0; i < N; i++)
	{
		char a[20];
		scanf("%s", a);

		int used = 0;
		for(int i=0; a[i]; i++)
			used |= 1 << (a[i] - '0');

		check[used]++;
	}

	long long ans = 0;
	for(int i=0; i < 1024; i++)
	{
		ans += 1LL * check[i] * (check[i] - 1) / 2;
		for(int j=i+1; j < 1024; j++)
			if(i & j)
				ans += 1LL * check[i] * check[j];
	}

	printf("%lld", ans);
	return 0;
}