#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	priority_queue<int> pq;
	while(N--)
	{
		int n;
		scanf("%d",&n);

		if(n)
			pq.push(n);
		else if(pq.empty())
			puts("0");
		else
		{
			printf("%d\n", pq.top());
			pq.pop();
		}
	}
	return 0;
}