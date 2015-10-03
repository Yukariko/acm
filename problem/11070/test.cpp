#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		long long add[1001] = {};
		long long sub[1001] = {};

		while(M--)
		{
			int a, b, p, q;
			scanf("%d%d%d%d",&a,&b,&p,&q);
			add[a] += p;
			add[b] += q;
			sub[a] += q;
			sub[b] += p;
		}

		long long mi = 987654321321LL, ma = 0;
		for(int i=1; i <= N; i++)
		{
			long long gide = 0;
			if(add[i] || sub[i])
				gide = 1000LL * add[i] * add[i] / (add[i] * add[i] + sub[i] * sub[i]);
			mi = min(mi, gide);
			ma = max(ma, gide);
		}
		printf("%lld\n%lld\n", ma, mi);
	}
	return 0;
}