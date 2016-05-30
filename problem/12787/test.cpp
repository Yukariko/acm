#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int O;
		scanf("%d", &O);

		if(O == 1)
		{
			char a[101];
			scanf("%s", a);

			unsigned long long ans = 0;

			stringstream b(a);
			for(int i=0; i < 8; i++)
			{
				int n;
				b >> n;
				b.ignore(1);
				ans = ans * 256 + n;
			}

			printf("%llu\n", ans);
		}
		else
		{
			unsigned long long n;
			scanf("%llu", &n);
			vector<int> a(8);
			for(int i=0; i < 8; i++)
			{
				a[i] = n % 256;
				n /= 256;
			}

			printf("%d", a[7]);
			for(int i=6; i >= 0; i--)
				printf(".%d", a[i]);
			puts("");
		}
	}
	return 0;
}