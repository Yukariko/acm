#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	string s;
	while(N)
	{
		s += '0' + N % 2;
		N /= 2;
	}

	int ans = 0;
	for(int i=0; s[i]; i++)
	{
		ans *= 2;
		ans += s[i] - '0';
	}

	printf("%d", ans);

	return 0;
}