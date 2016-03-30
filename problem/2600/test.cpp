#include <bits/stdc++.h>

using namespace std;

int a[3];
int cache[501][501];

bool solve(int p, int q)
{
	int& ans = cache[p][q];
	if(ans != -1)
		return ans;

	for(int i=0; i < 3; i++)
	{
		if(p >= a[i] && !solve(p - a[i], q))
			return ans = true;
		if(q >= a[i] && !solve(p, q - a[i]))
			return ans = true;
	}

	return ans = false;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	for(int i=0; i < 3; i++)
		scanf("%d", &a[i]);

	for(int i=0; i < 5; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		printf("%c\n", "BA"[solve(p, q)]);
	}
	return 0;
}