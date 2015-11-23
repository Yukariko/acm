#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		int maximum = 0;
		string ans;

		while(N--)
		{
			char a[21];
			int n;
			scanf("%s%d",a,&n);
			if(maximum < n)
			{
				maximum = n;
				ans = a;
			}
		}

		puts(ans.c_str());
	}
	return 0;
}