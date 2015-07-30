#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[100001];

long long getDistSum(int part)
{
	long long ans = 0;
	for(long long d=0, i=0; i < N; d += part, i++)
		ans += abs(a[i] - d);
	return ans;
}

int main()
{
	cin >> N;
	cin >> a[0];
	for(int i=1; i < N; i++)
		cin >> a[i];

	int start = 1, end = a[N-1];
	long long ans = 1LL << 62;
	while(start <= end)
	{
		int mid1 = start + (end - start) / 3;
		int mid2 = start + (end - start) * 2 / 3;
		long long d1 = getDistSum(mid1);
		long long d2 = getDistSum(mid2);

		ans = min(ans, min(d1,d2));

		if(d1 > d2)
			start = mid1 + 1;
		else if(d1 < d2)
			end = mid2 - 1;
		else
		{
			start = mid1 + 1;
			end = mid2 - 1;
		}
	}

	cout << ans;
	return 0;
}