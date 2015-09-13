#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> a(N);
	long long len = 0;
	for(int i=0; i < N; i++)
	{
		cin >> a[i];
		len += a[i];
	}

	len /= 2;
	int curStart = 0;
	long long curLen = 0;
	long long ans = 0;
	for(int i=0; i < N; i++)
	{
		curLen += a[i];
		while(curLen > len)
			curLen -= a[curStart++];
		ans = max(ans, curLen);
	}
	cout << ans;
	return 0;
}