#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<set<int>> a(N * 2);
	for(int i=0; i <= N; i++)
		a[i].insert(i);


	double begin = 0, end = N;
	for(int t=0; t < 3; t++)
	{
		int l, r;
		scanf("%d%d",&l,&r);

		int lpos = begin + 0.5, rpos = begin + 0.5;
		for(int i=begin + 0.5; a[i].find(l) == a[i].end(); i++)
			lpos++;
		for(int i=begin + 0.5; a[i].find(r) == a[i].end(); i++)
			rpos++;

		if(lpos == rpos)
			continue;

		double half = (lpos + rpos) / 2.0;
		int mpos = half + 0.5;

		if(half - begin <= end - half)
		{
			for(int i=0; i < mpos; i++)
				a[mpos * 2 - i - (mpos != half)].insert(a[i].begin(), a[i].end());
			begin = half;
		}
		else
		{
			for(int i=mpos; i <= end; i++)
				a[mpos * 2 - i - (mpos != half)].insert(a[i].begin(), a[i].end());
			end = half;
		}
	}

	printf("%.1f", end - begin);
	return 0;
}