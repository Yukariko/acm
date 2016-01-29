#include <bits/stdc++.h>

using namespace std;

int a[20001];

int main()
{
	priority_queue<long long> pq;
	
	int N;
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		pq.push(-a[i]);
	}

	long long ans = 0;

	while(pq.size() > 1)
	{
		long long A = -pq.top();
		pq.pop();
		long long B = -pq.top();
		pq.pop();

		pq.push(-A-B);
		ans += A+B;
	}
	
	printf("%lld", ans);
	return 0;
}