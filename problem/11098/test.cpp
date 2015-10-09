#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		vector< pair<int, string> > a(N);
		for(int i=0; i < N; i++)
			cin >> a[i].first >> a[i].second;

		sort(a.begin(), a.end());
		printf("%s\n", a[N-1].second.c_str());
	}
	return 0;
}