#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[300001];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < M; i++)
		scanf("%d", &a[i]);

	int left = 0, right = 1000000000;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		for(int i=0; i < M; i++)
			cnt += (a[i] + mid - 1) / mid;
		if(cnt <= N)
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d", left);
	return 0;
}