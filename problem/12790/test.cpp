#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		vector<int> a(8);
		for(int i=0; i < 8; i++)
			scanf("%d", &a[i]);

		for(int i=4; i < 8; i++)
			a[i-4] += a[i];

		a[0] = max(1, a[0]);
		a[1] = max(1, a[1]);
		a[2] = max(0, a[2]);

		printf("%d\n", a[0] + 5 * a[1] + 2 * a[2] + 2 * a[3]);
	}
	return 0;
}