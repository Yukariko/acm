#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	int sum = 0;
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}

	sort(a.begin(), a.end());

	printf("%.8f\n%.8f", (double)sum / N, (double)(a[N/2] + a[(N-1)/2]) / 2);
	return 0;
}