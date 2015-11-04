#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 89;

long long N;
char res[MAX_LEN+1];

long long cache[MAX_LEN][2];


long long solve(int pos, int cont)
{
	if(pos == MAX_LEN)
	{
		if(N-- == 0)
		{
			int start = 0;
			while(res[start+1] != 0 && res[start] == '0')
				start++;
			puts(res + start);
			exit(0);
		}
		return 1;
	}

	long long &ret = cache[pos][cont];
	if(ret != -1 && ret < N)
	{
		N -= ret;
		return ret;
	}

	res[pos] = '0';
	ret = solve(pos+1, 0);
	if(cont == 0)
	{
		res[pos] = '1';
		ret += solve(pos+1, 1);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%lld",&N);
	solve(0,0);
	return 0;
}