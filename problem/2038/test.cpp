#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > a;

int get_idx(int idx)
{
	int start = 0, end = a.size()-1;
	while(start <= end)
	{
		int mid = (start + end) / 2;
		if(idx < a[mid].first)
			end = mid -1;
		else if(idx >= a[mid].second)
			start = mid + 1;
		else
			return mid+1;
	}
}

int main()
{
	int N;
	scanf("%d",&N);

	int ans = 1;
	int plus = 2;

	a.push_back(make_pair(0,1));
	for(int i = 1; i < N;)
	{	
		a.push_back(make_pair(i, i + plus));
		i += plus;
		ans++;
		plus = get_idx(ans);
	}
	printf("%d",ans);
	return 0;
}