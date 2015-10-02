#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d",&N,&K);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	priority_queue<long long> pq;
	set<long long> visit;

	pq.push(-1);

	long long maxVal = 0;
	while(K)
	{
		long long pick = -pq.top();
		pq.pop();

		for(int i=0; i < N; i++)
		{
			long long npick = pick * a[i];
			if(pq.size() > K && npick > maxVal)
				continue;
			if(visit.find(npick) == visit.end())
			{
				maxVal = max(maxVal, npick);
				visit.insert(npick);
				pq.push(-npick);
			}
		}
		K--;
	}

	printf("%lld", -pq.top());
	return 0;
}