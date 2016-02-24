#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a.begin(), a.end());


	double left = 0, right = 0;
	double leftCnt = a[0].second, rightCnt = 0;

	for(int i=1; i < N; i++)
	{
		right += 1.0 * (a[i].first - a[0].first) * a[i].second;
		rightCnt += a[i].second;
	}

	double minDist = right;
	int ans = a[0].first;
	for(int i=1; i < N; i++)
	{
		right -= rightCnt * (a[i].first - a[i-1].first);
		left += leftCnt * (a[i].first - a[i-1].first);

		double dist = right + left;

		if(minDist > dist)
		{
			minDist = dist;
			ans = a[i].first;
		}

		rightCnt -= a[i].second;
		leftCnt += a[i].second;
	}

	printf("%d", ans);
	return 0;
}