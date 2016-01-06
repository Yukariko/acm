#include <bits/stdc++.h>

using namespace std;

int N;
int a[1001];
int b[1001];
int cache[1001][161];

const int INF = 987654321;
const int pad = 80;

int solve(int pos, int cnt)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos][cnt + pad];
	if(ans != -1)
		return ans;

	ans = INF;

	int diff = b[pos] - a[pos];
	if(cnt * diff < 0 || (cnt && diff == 0))
		return ans;
	if(abs(cnt) > abs(diff))
		return ans;

	if(diff >= 0)
		for(int i=0; i <= diff; i++)
			ans = min(ans, diff - cnt + solve(pos+1, i));
	else
		for(int i=0; i >= diff; i--)
			ans = min(ans, -diff + cnt + solve(pos+1, i));

	return ans;
}

int main()
{
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);
	for(int i=0; i < N; i++)
		scanf("%d",&b[i]);

	memset(cache, -1, sizeof(cache));
	printf("%d",solve(0,0));
	return 0;
}