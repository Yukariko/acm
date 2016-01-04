#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int cache[51][51][51][51];

int solve(int h1, int w1, int h2, int w2)
{
	if(h1 == h2 && w1 == w2 && h1 == w1)
		return 1;

	int& ans = cache[h1][w1][h2][w2];
	if(ans != -1)
		return ans;

	ans = INF;

	int w3 = w1 - w2;
	if(w1 == w2)
		w3 = w1;

	for(int i=1; i < h2; i++)
		ans = min(ans, solve(i, w3, i, w3) + solve(h1 - i, w1, h2 - i, w2));
	if(h2 < h1)
		ans = min(ans, solve(h2, w3, h2, w3) + solve(h1 - h2, w1, h1 - h2, w1));
	for(int i=h2 + 1; i < h1; i++)
		ans = min(ans, solve(i, w1, h2, w2) + solve(h1 - i, w1, h1 - i, w1));

	ans = min(ans, solve(w1, h1, w2, h2));
	return ans;
}

int main()
{
	int h1, w1, h2, w2;
	scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
	memset(cache, -1, sizeof(cache));
	printf("%d", solve(h1,w1,h2,w2));
	return 0;
}