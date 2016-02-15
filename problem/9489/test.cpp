#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	while(scanf("%d%d", &N, &K), N)
	{
		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		vector<int> parent(N+1, -1);

		int node[1001] = {};

		int nodeIdx = 0;
		int kthParent = -1;

		queue<int> q;
		q.push(nodeIdx++);

		while(nodeIdx < N)
		{
			int size = q.size();
			while(size-- && nodeIdx < N)
			{
				int here = q.front();
				q.pop();

				if(a[nodeIdx] == K)
					kthParent = here;
				node[here]++;
				parent[nodeIdx] = here;
				q.push(nodeIdx++);

				while(nodeIdx < N && a[nodeIdx-1] + 1 == a[nodeIdx])
				{
					if(a[nodeIdx] == K)
						kthParent = here;

					node[here]++;
					parent[nodeIdx] = here;
					q.push(nodeIdx++);
				}
			}
			if(kthParent != -1)
				break;
		}

		int ans = 0;
		for(int i=0; i < N; i++)
			if(i != kthParent && parent[i] == parent[kthParent])
				ans += node[i];
		printf("%d\n", ans);
	}
	return 0;
}