#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int N;
bool error[11];
bool visit[6000001];

vector<int> a;

void solve(int pos)
{
	if(pos > 6000000 || visit[pos])
		return;
	visit[pos] = true;

	a.push_back(pos);
	for(int i=0; i < 10; i++)
		if(error[i] == false)
			solve(pos * 10 + i);
}


int main()
{
	int M;
	cin >> N >> M;
	for(int i=0; i < M; i++)
	{
		int n;
		cin >> n;
		error[n] = true;
	}
	solve(0);
	int ans = abs(100 - N);
	for(int i=0; i < a.size(); i++)
	{
		if(error[0] == true && a[i] == 0)
			continue;

		int button = a[i] == 0;
		for(int t = a[i]; t; t /= 10)
			button++;
		ans = min(ans, button + abs(N - a[i]));
	}
	cout << ans;
	return 0;
}