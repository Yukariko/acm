#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());

	vector<int> b(N-1);
	for(int i=1; i < N; i++)
		b[i-1] = a[i] - a[i-1];
	sort(b.begin(), b.end());

	int sum = 0;
	for(int i=0; i < N-K; i++)
		sum += b[i];

	printf("%d", sum);
	return 0;
}