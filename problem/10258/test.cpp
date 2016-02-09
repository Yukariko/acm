#include <bits/stdc++.h>

using namespace std;

char a[32];
int cache[33];

long long pow2(int n)
{
	return 1LL << n;
}

int main()
{
	int T;
	scanf("%d ", &T);

	while(T--)
	{
		int len = strlen(gets(a));

		long long left = 0;

		for(int i=0; i < len; i++)
		{
			long long zb = pow2(len - i - 1);
			long long cycle = pow2(len - i);

			if(left < zb)
			{
				if(a[i] == '1')
					left = zb;
			}
			else
			{
				char curToggle = ((left - zb) / cycle) % 2? '0': '1';
				long long idx = (left - zb) % cycle;
				if(curToggle != a[i])
				{
					left += cycle - idx;
				}
			}
		}

		printf("%lld\n", left);
	}
	return 0;
}