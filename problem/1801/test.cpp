#include <bits/stdc++.h>

using namespace std;

int N;
int a[16];
vector< vector<short> > cache[16][80][80];

short solve(int pos, int as, int bs, int cs, int ds)
{
	short max_ret = 0;
	if(as == bs && cs == ds)
		max_ret = max(max_ret, (short)(as * cs));

	if(pos == N)
		return max_ret;

	if(cache[pos][as][bs].size() <= cs || cache[pos][as][bs][cs].size() <= ds)
		return 0;

	short& ret = cache[pos][as][bs][cs][ds];
	if(ret != -1)
		return ret;

	ret = max_ret;
	if(as + a[pos] < 80)
		ret = max(ret, solve(pos+1, as + a[pos], bs, cs, ds));
	if(bs + a[pos] < 80)
		ret = max(ret, solve(pos+1, as, bs + a[pos], cs, ds));
	if(cs + a[pos] <= 40)
		ret = max(ret, solve(pos+1, as, bs, cs + a[pos], ds));
	if(ds + a[pos] <= 40)
		ret = max(ret, solve(pos+1, as, bs, cs, ds + a[pos]));
	ret = max(ret, solve(pos+1, as, bs, cs, ds));
	return ret;
}
int main()
{
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	for(int i=0; i <= 40; i++)
		for(int j=0; j <= 40; j++)
			for(int p=0; p < N; p++)
				cache[p][i][j] = vector< vector<short> >(41, vector<short>(41, -1));

	for(int i=41; i < 80; i++)
		for(int j=0; j < 80; j++)
			{
				int k = 80 - max(i,j);
				for(int p=0; p < N; p++)
					cache[p][i][j] = vector< vector<short> >(k+1, vector<short>(k+1, -1));
			}

	int ans = solve(0,0,0,0,0);
	printf("%d",ans? ans: -1);
	return 0;
}	