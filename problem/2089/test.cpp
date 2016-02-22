#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long N;
	scanf("%lld", &N);

	int bit;
	if(N >= 0)
	{
		bit = 1;
		long long l = 0, r = 1;

		while(r < N)
		{
			l = r + 1;
			r = l * 2 + 1;

			bit += 2;
		}
	}
	else
	{
		bit = 2;
		long long l = -1, r = -2;
		while(r > N)
		{
			l = r - 1;
			r = l * 2 - 1;

			bit += 2;
		}
	}

	string ans;
	long long sum = 0;
	long long sub = 0;
	for(long long i=0; i < bit; i++)
		if(i % 2 == 1)
			sub += 1LL << i;
		else
			sum += 1LL << i;

	long long num = 0;
	for(long long i=bit-1; i >= 0; i--)
	{
		if(i % 2 == 0 && num + (1LL << i) - sub <= N)
		{
			ans += '1';
			num += 1LL << i;
		}
		else if(i % 2 == 1 && num - (1LL << i) + sum >= N)
		{
			ans += '1';
			num -= 1LL << i;
		}
		else
			ans += '0';

		if(i % 2 == 1)
			sub -= 1LL << i;
		else
			sum -= 1LL << i;
	}

	int readingZero = 0;
	while(ans != "0" && ans[readingZero] == '0')
		readingZero++;
	puts(ans.c_str() + readingZero);
	return 0;
}