#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	int a[] = {500, 100, 50, 10, 5, 1};

	N = 1000 - N;

	int ans = 0;
	for(int i=0; i < 6; i++)
	{
		ans += N / a[i];
		N -= N / a[i] * a[i];
	}
	printf("%d",ans);
	return 0;
}