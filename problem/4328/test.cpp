#include <bits/stdc++.h>

using namespace std;

int main()
{
	int B;
	char a[1001];
	char b[10];

	while(scanf("%d", &B), B)
	{
		scanf("%s%s", a, b);

		long long m = strtol(b, 0 , B);

		long long n = 0;
		for(int i=0; a[i]; i++)
		{
			n = n * B + a[i] - '0';
			n %= m;
		}

		string ans;
		while(n)
		{
			ans += n % B + '0';
			n /= B;
		}
		if(ans.empty())
			ans += '0';
		reverse(ans.begin(), ans.end());
		puts(ans.c_str());
	}

	return 0;
}