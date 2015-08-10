#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int a[K];
	for(int i=0; i < K; i++)
		cin >> a[i];

	if(M == 0)
	{
		cout << string(K, '0');
		return 0;
	}

	int start = 1, end = N;
	while(start <= end)
	{
		int mid = (start + end) / 2;
		int cnt = 1;
		int dist = 0;
		for(int i=1; i < K; i++)
		{
			dist += a[i] - a[i-1];
			if(dist >= mid)
			{
				cnt++;
				dist = 0;
			}
		}

		if(cnt >= M)
			start = mid + 1;
		else
			end = mid - 1;
	}

	int dist = 0;
	cout << 1;
	M--;
	for(int i=1; i < K; i++)
	{
		dist += a[i] - a[i-1];
		if(M && dist >= end)
		{
			cout << 1;
			dist = 0;
			M--;
		}
		else
			cout << 0;
	}	

	return 0;
}