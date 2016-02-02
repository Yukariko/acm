#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ans = 0;
	for(int i=0; i < 4; i++)
	{
		int n;
		scanf("%d", &n);
		ans += n;
	}

	printf("%d\n%d", ans / 60, ans % 60);
	return 0;
}