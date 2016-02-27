#include <bits/stdc++.h>

using namespace std;

int gcd(int p, int q)
{
	return q? gcd(q, p % q): p;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		vector<int> b(1000000, 0);
		for(int ans = N; ; ans++)
		{
			bool success = true;
			for(int i=0; i < N; i++)
			{
				if(b[a[i] % ans] == ans)
				{
					success = false;
					break;
				}

				b[a[i] % ans] = ans;
			}
			if(success)
			{
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}