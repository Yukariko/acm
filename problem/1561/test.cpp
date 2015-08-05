#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getAns(int *a, int M, long long mid)
{
	if(mid < 0)
		return 0;
	long long ans = M;
	for(int i=0; i < M; i++)
		ans += mid / a[i];
	return ans;
}

long long getMod(int *a, int M, long long mid)
{
	long long ans = 0;
	for(int i=0; i < M; i++)
		ans += mid % a[i] == 0;
	return ans;
}

int main()
{
	int N, M;
	int a[10001];
	cin >> N >> M;

	for(int i=0; i < M; i++)
		cin >> a[i];

	long long start = 0, end = N * 30LL;
	while(start <= end)
	{
		long long mid = (start + end) / 2;
		long long ans = getAns(a, M, mid-1);
		long long mod = getMod(a, M, mid);

		if(N > ans && ans + mod >= N)
		{
			for(int i=0; i < M; i++)
			{
				if(mid % a[i] == 0)
				{
					ans++;
					if(ans == N)
					{
						cout << i+1;
						return 0;
					}
				}
			}
			return 0;
		}

		if (ans + mod < N)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}