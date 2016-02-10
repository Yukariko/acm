#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h1, m1, s1, h2, m2, s2;
	while(~scanf("%d%d%d%d%d%d", &h1, &m1, &s1, &h2, &m2, &s2))
	{
		int a = h1 * 3600 + m1 * 60 + s1;
		int b = h2 * 3600 + m2 * 60 + s2;
		int ans = (b - a + 3600 * 24) % (3600 * 24);
		printf("%d %d %d\n", ans / 3600, ans % 3600 / 60, ans % 60);
	}
	return 0;
}