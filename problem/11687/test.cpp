#include <bits/stdc++.h>

using namespace std;

int main()
{
	int M;
	scanf("%d", &M);

	bool find = false;

	int start = 0, end = 5 * 100000000;
	while(start <= end)
	{
		int mid = (start + end) / 2;
		int cnt = 0;
		for(int i=5; i <= mid; i*=5)
			cnt += mid / i;

		if(cnt >= M)
		{
			if(cnt == M)
				find = true;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	printf("%d", find? start: -1);
	return 0;
}