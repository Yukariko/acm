#include <bits/stdc++.h>

using namespace std;

bool check(const pair<int, int>& p, const pair<int, int>& q, const pair<int, int>& r)
{
	int dy = p.second - q.second;
	int dx = p.first - q.first;

	if(dy == 0)
		return p.second == r.second;
	if(dx == 0)
		return p.first == r.first;
	return dy * (r.first - p.first) == dx * (r.second - p.second);
}

int main()
{
	int N;
	scanf("%d", &N);

	char a[101][101];
	vector<pair<int, int>> b;
	for(int i=0; i < N; i++)
	{
		scanf("%s", a[i]);
		for(int j=0; j < N; j++)
			if(a[i][j] != '.')
				b.push_back({i, j});
	}

	int ans = 0;
	for(size_t i=0; i < b.size(); i++)
		for(size_t j=i+1; j < b.size(); j++)
			for(size_t k=j+1; k < b.size(); k++)
				if(check(b[i], b[j], b[k]))
					ans++;
	printf("%d", ans);
	return 0;
}
