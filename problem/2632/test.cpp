#include <bits/stdc++.h>

using namespace std;

int K, M, N;
vector<int> a, b;
vector<int> asum, bsum;

void init_sum(vector<int>& vsum, const vector<int>& v)
{
	int N = v.size();
	vsum.push_back(0);

	for(int i=0; i < N; i++)
	{
		int sum = 0;
		for(int j=0; j < N-1; j++)
		{
			sum += v[(i+j) % N];
			vsum.push_back(sum);
		}
	}

	int sum = 0;
	for(int i=0; i < N; i++)
		sum += v[i];
	vsum.push_back(sum);

	sort(vsum.begin(), vsum.end());
}

int main()
{
	scanf("%d%d%d",&K,&M,&N);
	a = vector<int>(M);
	b = vector<int>(N);
	for(int i=0; i < M; i++)
		scanf("%d",&a[i]);
	for(int i=0; i < N; i++)
		scanf("%d",&b[i]);

	init_sum(asum, a);
	init_sum(bsum, b);

	int ans = 0;
	for(auto &pick : asum)
	{
		ans += upper_bound(bsum.begin(), bsum.end(), K - pick) - 
					 lower_bound(bsum.begin(), bsum.end(), K - pick);
	}

	printf("%d",ans);
	return 0;
}