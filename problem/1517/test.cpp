#include <bits/stdc++.h>

using namespace std;

struct FenwickTree
{
	vector<int> tree;
	FenwickTree(int n) :tree(n+1,0) {}

	int sum(int pos)
	{
		++pos;
		int ret = 0;
		while(pos)
		{
			ret += tree[pos];
			pos &= pos - 1;
		}
		return ret;
	}

	void add(int pos, int val)
	{
		++pos;
		while(pos < tree.size())
		{
			tree[pos] += val;
			pos += pos & -pos;
		}
	}
};

int main()
{
	int N;
	scanf("%d",&N);

	FenwickTree ft(N);
	vector<pair<int,int>> a(N);
	for(int i=0; i < N; i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
		ft.add(i, 1);
	}

	sort(a.begin(), a.end());

	long long ans = 0;
	for(int i=0; i < N; i++)
	{
		if(a[i].second == 0)
		{
			ft.add(0, -1);
			continue;
		}
		ans += ft.sum(a[i].second-1);
		ft.add(a[i].second-1, -1);
	}
	printf("%lld\n",ans);
	return 0;
}