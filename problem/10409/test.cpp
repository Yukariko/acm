#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int sum = 0;
	int ans = 0;
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d", &n);

		if(sum + n > M)
			break;
		sum += n;
		ans++;
	}

	printf("%d", ans);
	return 0;
}