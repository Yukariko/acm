#include <bits/stdc++.h>

using namespace std;

bool numSet[100000001];

int main()
{
	int N;
	scanf("%d", &N);

	unsigned int ans = 1;

	for(long long i=2; i <= N; i++)
	{
		if(numSet[i] == false)
		{
			for(int n = N / i; n; n /= i)
				ans *= i;

			for(long long j = i * i; j <= N; j+=i)
				numSet[j] = true;
		}
	}

	printf("%u", ans);

	return 0;
}