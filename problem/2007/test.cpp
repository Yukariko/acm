#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N * (N-1) / 2);
	map<int, int> ck;
	for(size_t i=0; i < a.size(); i++)
	{
		scanf("%d", &a[i]);
		ck[a[i]]++;
	}

	if(N == 1)
		puts("1");
	else if(N == 2)
	{
		int ans[2] = {1, a[0] - 1};
		if(ans[0] > ans[1])
			swap(ans[0], ans[1]);
		printf("%d %d", ans[0], ans[1]);
	}
	else
	{
		sort(a.begin(), a.end());

		for(size_t i=2; i < a.size(); i++)
		{
			vector<int> b(N);
			if((a[0] + a[1] - a[i]) % 2)
				continue;
			b[0] = (a[0] + a[1] - a[i]) / 2;

			map<int, int> mod;

			bool find = true;
			int cnt = 1;
			for(size_t j=0; j < a.size(); j++)
			{
				if(mod[a[j]] == ck[a[j]])
					continue;

				b[cnt] = a[j] - b[0];
				for(size_t k=0; k < cnt; k++)
					if(++mod[b[cnt] + b[k]] > ck[b[cnt] + b[k]])
					{
						find =  false;
						break;
					}
				cnt++;
				if(cnt == N)
					break;
			}

			if(find)
			{
				for(int j=0; j < N; j++)
					printf("%d ", b[j]);
				return 0;
			}
		}
		puts("Impossible");
	}
	return 0;
}