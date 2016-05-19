#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	map<int, int> tree;
	tree[0] = 0;
	tree[N+1] = 0;

	long long counter = 0;
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d", &n);

		auto it = tree.lower_bound(n);
		int m = it->second;
		m = max(m, (--it)->second);

		tree[n] = m + 1;
		counter += m;

		printf("%lld\n", counter);
	}

	return 0;
}