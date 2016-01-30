#include <bits/stdc++.h>

using namespace std;

int main()
{
	int R, N;
	int a[1001];
	while(scanf("%d%d", &R, &N), R != -1)
	{
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		sort(a, a + N);

		int left = a[0];
		int ans = 0;
		for(int i=1; i < N; i++)
		{
			if(a[i] - left > R)
			{
				ans++;
				int place = i - 1;
				while(i < N && a[place] + R >= a[i])
					i++;
				if(i < N)
					left = a[i];
				else
					left = -1;
			}
		}

		if(left != -1)
			ans++;

		printf("%d\n", ans);
	}
	return 0;
}