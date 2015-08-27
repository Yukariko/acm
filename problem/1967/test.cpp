#include <iostream>
#include <algorithm>

using namespace std;

int longest;

int height(const vector< vector< pair<int,int> > >& a, int pos)
{
	vector<int> heights;
	for(int i=0; i < a[pos].size(); i++)
		heights.push_back(a[pos][i].second + height(a, a[pos][i].first));

	if(heights.empty())
		return 0;

	sort(heights.begin(), heights.end());

	if(heights.size() >= 2)
		longest = max(longest, heights[heights.size()-1] + heights[heights.size()-2]);
	return heights.back();
}
int solve(const vector< vector< pair<int,int> > >& a)
{
	int h = height(a, 1);
	return max(longest, h);
}

int main()
{
	int N;
	cin >> N;

	vector< vector< pair<int,int> > > a(N+1);
	for(int i=0; i < N; i++)
	{
		int no;
		cin >> no;

		int v, w;
		cin >> v >> w;
		a[no].push_back(make_pair(v,w));
	}
	cout << solve(a);
	return 0;
}