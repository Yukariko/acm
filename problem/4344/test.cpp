#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		int sum = 0;
		vector<int> a(N);
		for(int i=0; i < N; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}

		int average = sum / N;

		int ans = 0;
		for(int i=0; i < N; i++)
			if(a[i] > average)
				ans++;

		printf("%.3f%%\n", (double)ans / N * 100);
	}
	return 0;
}