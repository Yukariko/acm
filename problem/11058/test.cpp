#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	long long d[101] = {};
	for(int i=1; i <= N; i++)
	{
		d[i] = max(d[i], d[i-1] + 1);
		for(int j=i+3; j <= N; j++)
			d[j] = max(d[j], d[i] * (j - i - 1));
	}

	printf("%lld", d[N]);
	return 0;
}