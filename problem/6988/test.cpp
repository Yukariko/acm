#include <bits/stdc++.h>

using namespace std;

bool check[1000001];

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		check[a[i]] = true;
	}

	int ans = 0;

	for(int i=0; i < N; i++)
	{
		for(int j=i+1; j < N; j++)
		{
			int diff = a[j] - a[i];
			int count = 0;
			int sum = 0;
			for(int num = a[i]; num <= 1000000 && check[num]; num += diff)
			{
				sum += num;
				count++;
			}

			if(count >= 3)
				ans = max(ans, sum);
		}
	}

	printf("%d",ans);
	return 0;
}