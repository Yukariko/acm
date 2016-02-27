#include <bits/stdc++.h>

using namespace std;

int main()
{
	int order[3] = {0, 1, 2};
	int a[3];
	scanf("%d:%d:%d", &a[0], &a[1], &a[2]);

	int ans = 0;
	do
	{
		int h = order[0], m = order[1], s = order[2];
		bool success = true;
		if(a[h] < 1 || a[h] > 12)
			success = false;
		if(a[m] < 0 || a[m] > 59)
			success = false;
		if(a[s] < 0 || a[s] > 59)
			success = false;
		if(success)
			ans++;
	}	while(next_permutation(order, order + 3));

	printf("%d", ans);
	return 0;
}