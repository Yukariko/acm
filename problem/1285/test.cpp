#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	char a[21][21];
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int ans = N * N;
	for(int i=0; i < (1 << N); i++)
	{
		int cnt = 0;
		for(int j=0; j < N; j++)
		{
			int rcnt = 0;
			for(int k=0; k < N; k++)
			{
				char tok = i & (1 << k)? 'H': 'T';
				if(a[j][k] == tok)
					rcnt++;
			}
			cnt += min(rcnt, N - rcnt);
		}
		ans = min(ans, cnt);
	}

	printf("%d", ans);
	return 0;
}