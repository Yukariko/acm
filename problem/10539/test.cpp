#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int sum = 0;
	for(int i=1; i <= N; i++)
	{
		int n;
		scanf("%d", &n);
		n = n * i - sum;
		sum += n;
		printf("%d ", n);
	}
	return 0;
}