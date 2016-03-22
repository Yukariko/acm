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

		vector<int> a(N);
		for(int i=0; i < N; i++)
		{
			scanf("%d" ,&a[i]);
			a[i]--;
		}

		vector<bool> check(N, false);
		int ans = 0;
		int sel = 0;

		while(check[sel] == false)
		{
			if(sel == N-1)
				break;
			check[sel] = true;
			sel = a[sel];
			ans++;
		}

		if(sel != N-1)
			puts("0");
		else
			printf("%d\n", ans);
	}
	return 0;
}