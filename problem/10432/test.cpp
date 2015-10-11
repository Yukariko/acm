#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int tc;
		scanf("%d",&tc);

		int a[12];
		for(int i=0; i < 12; i++)
			scanf("%d",&a[i]);

		int ans = 0;
		for(int i=1; i <= 11; i++)
			for(int j=1; j <= 12-i; j++)
			{
				bool find = true;
				for(int k=0; k < i; k++)
					if(a[j+k] <= a[j-1] || a[j+k] <= a[j+i])
						find = false;
				if(find)
					ans++;
			}

		printf("%d %d\n", tc, ans);
	}
	return 0;
}