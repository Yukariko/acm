#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> start, _end, length;
int N, D;
int cache[10001];

int solve(int pos)
{
	if(pos >= D)
		return 0;
	int& ret = cache[pos];
	if(ret)
		return ret;

	ret = D - pos;
	for(int i=0; i < N; i++)
		if(pos <= start[i])
			ret = min(ret, start[i] - pos + length[i] + solve(_end[i]));

	return ret;
}

int main()
{
	cin >> N >> D;
	for(int i=0; i < N; i++)
	{
		int S,E,L;
		cin >> S >> E >> L;
		if(E > D || E - S < L)
			continue;
		start.push_back(S);
		_end.push_back(E);
		length.push_back(L);
	}
	N = start.size();
	cout << solve(0);
	return 0;
}