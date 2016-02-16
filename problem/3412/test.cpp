#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		int ans = 0;
		for(int i=0; i < N; i++)
		{
			int y, x;
			scanf("%d%d", &y, &x);

			int r = 0;
			while(r * r < y * y + x * x)
				r++;

			if(r == 0)
				ans += 10;
			else if(r <= 200)
				ans += 11 - (r + 19) / 20 ;
		}
		printf("%d\n", ans);
	}
	return 0;
}