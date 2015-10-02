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

		int a[21];
		int ans = 0;
		for(int i=0; i < 20; i++)
		{
			int n;
			int pos = -1;
			scanf("%d",&n);
			for(int j=0; j < i; j++)
				if(a[j] > n)
				{
					pos = j;
					break;
				}
			if(pos == -1)
			{
				a[i] = n;
				continue;
			}
			for(int j=i; j > pos; j--)
			{
				a[j] = a[j-1];
				ans++;
			}
			a[pos] = n;
		}

		printf("%d %d\n", tc, ans);
	}
	return 0;
}