#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[51];
int b[51];
map<int, int> factor;

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i=0; i < M; i++)
		scanf("%d", &b[i]);

	for(int i=0; i < M; i++)
	{
		vector<int> c;
		for(int j=1; j * j <= b[i]; j++)
		{
			if(b[i] % j == 0)
			{
				c.push_back(j);
				if(j != b[i] / j)
					c.push_back(b[i] / j);
			}
		}

		for(size_t j=0; j < c.size(); j++)
			factor[c[j]]++;
	}

	int ans = 0;
	for(auto& pick : factor)
	{
		if(pick.second == M)
		{
			ans++;
			for(int i=0; i < N; i++)
				if(pick.first % a[i])
				{
					ans--;
					break;
				}
		}
	}

	printf("%d", ans);
	return 0;
}