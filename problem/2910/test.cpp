#include <bits/stdc++.h>

using namespace std;

struct Num
{
	int n, order, cnt;
};

int main()
{
	int N, C;
	scanf("%d%d", &N, &C);

	vector<int> a(N);
	map<int, pair<int, int>> b;
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		if(b[a[i]].first == 0)
			b[a[i]].second = i;
		b[a[i]].first--;
	}

	vector<pair<int, int>> c;
	for(auto &pick : b)
		c.push_back(pick.second);
	
	sort(c.begin(), c.end());

	for(size_t i=0; i < c.size(); i++)
		while(c[i].first++)
			printf("%d ", a[c[i].second]);

	return 0;
}