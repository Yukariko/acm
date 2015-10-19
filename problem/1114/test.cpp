#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int L, K, C;
	int a[10001];

	cin >> L >> K >> C;
	for(int i=0; i < K; i++)
		cin >> a[i];

	a[K++] = L;
	a[K++] = 0;
	sort(a, a + K);

	int start = 0, end = L;
	int ret=L, first;
	while(start <= end)
	{
		int mid = (start + end) / 2;		
		int chance = C;
		int cur = a[K-1];
		int maxPiece = 0;
		bool find = true;

		for(int i=K-2; i >= 0; i--)
		{
			if(a[i] - a[i+1] > mid)
			{
				find = false;
				break;
			}
			if(cur - a[i] > mid || i < chance)
			{
				maxPiece = max(maxPiece, cur - a[i+1]);
				cur = a[i+1];
				chance--;
			}
		}

		if(chance < 0 || cur > mid)
			find = false;

		if(!find)
			start = mid + 1;
		else
		{
			maxPiece = max(maxPiece, cur);
			if(ret > maxPiece)
			{
				ret = maxPiece;
				first = cur;
			}
			end = mid - 1;
		}
	}

	cout << ret << " " << first;
	return 0;
}