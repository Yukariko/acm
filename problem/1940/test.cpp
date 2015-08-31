#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> a(N);
	for(int i=0; i < N; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int ans = 0;
	for(int i=0; i < N; i++)
		ans += upper_bound(a.begin(), a.end(), M - a[i]) - lower_bound(a.begin(), a.end(), M - a[i]);
	cout << ans / 2;
	return 0;
}