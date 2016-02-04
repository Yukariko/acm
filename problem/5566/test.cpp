#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int a[1001];
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	int pos = 0;

	while(M--)
	{
		int n;
		scanf("%d", &n);

		pos += n;
		pos += a[pos];
		ans++;

		if(pos >= N-1)
			break;
	}

	printf("%d", ans);
	return 0;
}