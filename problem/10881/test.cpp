#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

pair<int,int> swap(pair<int,int> p)
{
	return make_pair(p.second, p.first);
}

pair<int,int> merge(pair<int,int> p, pair<int,int> q)
{
	return make_pair(p.first + q.first, max(p.second,q.second));
}

int getSize(pair<int,int> p, pair<int,int> q)
{
	return min((p.first + q.first) * max(p.second,q.second), (p.second + q.second) * max(p.first,q.first));
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		vector< pair<int, int> > a(3);
		for(int i=0; i < 3; i++)
			cin >> a[i].first >> a[i].second;

		int ans = 987654321;
		ans = min(ans, getSize(merge(a[0],a[1]),a[2]));
		ans = min(ans, getSize(merge(swap(a[0]),a[1]),a[2]));
		ans = min(ans, getSize(merge(swap(a[0]),swap(a[1])),a[2]));
		ans = min(ans, getSize(merge(swap(a[0]),a[1]),swap(a[2])));
		ans = min(ans, getSize(merge(swap(a[0]),swap(a[1])),swap(a[2])));
		ans = min(ans, getSize(merge(a[0],swap(a[1])),swap(a[2])));
		ans = min(ans, getSize(merge(a[0],swap(a[1])),a[2]));
		ans = min(ans, getSize(merge(a[0],a[1]),swap(a[2])));

		ans = min(ans, getSize(a[0],merge(a[1],a[2])));
		ans = min(ans, getSize(swap(a[0]),merge(a[1],a[2])));
		ans = min(ans, getSize(swap(a[0]),merge(swap(a[1]),a[2])));
		ans = min(ans, getSize(swap(a[0]),merge((a[1]),swap(a[2]))));
		ans = min(ans, getSize(swap(a[0]),merge(swap(a[1]),swap(a[2]))));
		ans = min(ans, getSize(a[0],merge(swap(a[1]),a[2])));
		ans = min(ans, getSize(a[0],merge(swap(a[1]),swap(a[2]))));
		ans = min(ans, getSize(a[0],merge(a[1],swap(a[2]))));

		ans = min(ans, getSize(merge(a[0],a[2]),a[1]));
		ans = min(ans, getSize(merge(swap(a[0]),a[2]),a[1]));
		ans = min(ans, getSize(merge(swap(a[0]),swap(a[2])),a[1]));
		ans = min(ans, getSize(merge(swap(a[0]),a[2]),swap(a[1])));
		ans = min(ans, getSize(merge(swap(a[0]),swap(a[2])),swap(a[1])));
		ans = min(ans, getSize(merge(a[0],swap(a[2])),a[1]));
		ans = min(ans, getSize(merge(a[0],swap(a[2])),swap(a[1])));
		ans = min(ans, getSize(merge(a[0],a[2]),swap(a[1])));
		cout << ans << '\n';
	}
	return 0;
}