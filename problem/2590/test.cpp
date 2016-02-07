#include <bits/stdc++.h>

using namespace std;

int a[7];

int main()
{
	for(int i=1; i <= 6; i++)
		scanf("%d", &a[i]);

	int ans = a[6];

	while(a[5])
	{
		a[5]--;
		a[1] -= min(11, a[1]);
		ans++;
	}

	while(a[4])
	{
		a[4]--;
		int pick = min(a[2], 5);
		a[2] -= pick;
		a[1] -= min(20 - pick * 4, a[1]);
		ans++;
	}

	while(a[3])
	{
		int pick = min(4, a[3]);
		a[3] -= pick;
		ans++;

		if(pick == 4)
			continue;

		int pick2;
		if(pick == 3)
			pick2 = 1;
		else if(pick == 2)
			pick2 = 3;
		else if(pick == 1)
			pick2 = 5;

		pick2 = min(a[2], pick);
		a[2] -= pick2;
		a[1] -= min(36 - pick * 9 - pick2 * 4, a[1]);
	}

	while(a[2])
	{
		int pick = min(9, a[2]);
		a[2] -= pick;
		a[1] -= min(36 - pick * 4, a[1]);
		ans++;
	}

	while(a[1])
	{
		a[1] -= min(11, a[1]);
		ans++;
	}

	printf("%d", ans);
	return 0;
}