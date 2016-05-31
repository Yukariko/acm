#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long N, K;
	scanf("%lld%lld", &N, &K);

	bool a[11] = {};
	for(long long i=N; i; i /= 10)
		a[i % 10] = true;

	int ans = 0;
	for(int i=0; i < 10; i++)
		ans += a[i];

	if(ans == K)
	{
		printf("%lld", N);
		return 0;
	}

	for(long long i=1, j=0; ; i *= 10, j++)
	{
		for(int p=1; p <= 9; p++)
		{
			long long n = N + i * p;

			char a[101];
			int l = sprintf(a, "%lld", n);

			bool b[11] = {};
			for(int k=0; k < l - j; k++)
				b[a[k] - '0'] = true;

			int cnt = K;
			for(int i=0; i < 10; i++)
				cnt -= b[i];

			if(cnt < 0)
				continue;

			int min = 0;
			for(int i=0; i < 10; i++)
				if(b[i])
				{
					min = i;
					break;
				}

			for(int i=l-j; i < l; i++)
			{
				if(cnt == 0)
					a[i] = min + '0';
				else
				{
					if(l - i > cnt)
					{
						if(!b[0])
						{
							b[0] = true;
							cnt--;
						}
						a[i] = '0';
					}
					else
					{
						int sel = -1;
						for(int i=0; i < 10 && sel == -1; i++)
							if(!b[i])
								sel = i;
						b[sel] = true;
						cnt--;
						a[i] = sel + '0';
					}
				}
			}

			if(cnt == 0)
			{
				puts(a);
				return 0;
			}
		}
	}
	return 0;
}