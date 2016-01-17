#include <bits/stdc++.h>

using namespace std;

const int tok = 500 * 30;

int N;
int a[31];
bool visit[31][500*30*2+1];
bool check[500*30*2+1];
bool solve(int pos, int sum)
{
	if(pos == N)
	{
		check[sum + tok] = true;
		return true;
	}

	bool& ans = visit[pos][sum + tok];
	if(ans)
		return ans;
	ans = max(solve(pos + 1, sum), solve(pos + 1, sum + a[pos]));
	ans = max(ans, solve(pos + 1 , sum - a[pos]));
	return ans;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	solve(0, 0);

	int M;
	scanf("%d", &M);

	while(M--)
	{
		int n;
		scanf("%d", &n);
		printf("%c ", check[n + tok]? 'Y': 'N');
	}
	return 0;
}