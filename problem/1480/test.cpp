#include <bits/stdc++.h>

using namespace std;

int N, M, C;
int cache[11][21][1<<13];
int a[14];

int solve(int pos, int weight, int pick)
{
	if(pos == M)
		return 0;

	int& ans = cache[pos][weight][pick];
	if(ans != -1)
		return ans;

	ans = solve(pos+1, C, pick);
	for(int i = 0; i < N; i++)
		if(a[i] <= weight && (pick & (1 << i)) == 0)
			ans = max(ans, 1 + solve(pos, weight - a[i], pick | (1 << i)));

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d",&N,&M,&C);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);
	printf("%d", solve(0, C, 0));
	return 0;
}