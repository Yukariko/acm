#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a[3], b[2];
	while(scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &b[0], &b[1]), a[0])
	{
		vector<bool> ck(53, false);
		sort(a, a + 3);
		sort(b, b + 2);

		for(int i=0; i < 3; i++)
			ck[a[i]] = true;

		for(int i=0; i < 2; i++)
			ck[b[i]] = true;

		int lose = 0;
		for(int i=0; i < 2; i++)
		{
			for(int j=0; j < 3; j++)
			{
				if(b[i] < a[j])
				{
					a[j] = 0;
					lose++;
					break;
				}
			}
		}
		if(lose == 2)
		{
			puts("-1");
			continue;
		}

		int ret = max({a[0], a[1], a[2]}) + 1;
		if(lose == 0)
			ret = 1;
		while(ret <= 52 && ck[ret])
			ret++;

		if(ret > 52)
			puts("-1");
		else
			printf("%d\n", ret);
	}
	return 0;
}