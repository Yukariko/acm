#include <bits/stdc++.h>

using namespace std;

int nCm[2001][2001];
void calc_nCm(int N, int MOD)
{
	for(int i=0; i <= N; i++)
		nCm[i][0] = nCm[i][i] = 1;
	for(int i=1; i <= N; i++)
		for(int j=1; j < i; j++)
			nCm[i][j] = (nCm[i-1][j] + nCm[i-1][j-1]) % MOD;
}


int main()
{
	long long N, K;
	int M;
	scanf("%lld%lld%d",&N,&K,&M);

	calc_nCm(M, M);

	vector<int> a, b;

	for(long long i=N, j=K; i; i /= M, j /= M)
	{
		a.push_back(i % M);
		b.push_back(j % M);
	}
	
	int ans = 1;
	for(size_t i=0; i < a.size(); i++)
		if(a[i] >= b[i])
			ans = (ans * nCm[a[i]][b[i]]) % M;
		else
			ans = 0;

	printf("%d",ans);
	return 0;
}