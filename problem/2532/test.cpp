#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int>& p, const pair<int,int>& q)
{
	if(p.first != q.first)
		return p.first < q.first;
	return p.second > q.second;
}

int lis(const vector< pair<int, int> >& a)
{
	vector<int> b;
	for(auto &p : a)
	{
		auto lo = upper_bound(b.begin(), b.end(), -p.second);
		if(lo == b.end())
			b.push_back(-p.second);
		else
			*lo = -p.second;
	}
	return b.size();
}

int main()
{
	int N;
	scanf("%d",&N);

	vector< pair<int,int> > a(N);
	for(int i=0; i < N; i++)
		scanf("%*d%d%d", &a[i].first, &a[i].second);

	sort(a.begin(), a.end(),cmp);
	a.erase(unique(a.begin(),a.end()),a.end());

	printf("%d", lis(a));

	return 0;
}