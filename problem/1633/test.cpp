#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int> > a;

int cache[1001][16][16];

int solve(int pos, int black, int white)
{
	if(pos == a.size())
		return 0;

	int& ret = cache[pos][black][white];
	if(ret != -1)
		return ret;

	ret = solve(pos+1, black, white);
	if(black < 15)
		ret = max(ret, a[pos].first + solve(pos+1, black+1, white));
	if(white < 15)
		ret = max(ret, a[pos].second + solve(pos+1, black, white+1));

	return ret;
}

int main()
{
	memset(cache,-1,sizeof(cache));

	int P, Q;
	while(cin >> P >> Q, !cin.eof())
		a.push_back(make_pair(P,Q));

	cout << solve(0, 0, 0);
	return 0;
}