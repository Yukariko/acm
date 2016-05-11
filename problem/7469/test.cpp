#include <bits/stdc++.h>

using namespace std;

const int DIV = 1000;

inline int idx(int n)
{
	return n / DIV;
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	vector<vector<pair<int, int>>> b(idx(N) + 1);
	for(int i=0; i < N; i++)
		b[idx(i)].push_back({a[i], i});

	for(size_t i=0; i < b.size(); i++)
		sort(b[i].begin(), b[i].end());

	sort(a.begin(), a.end());

	while(M--)
	{
		int L, R, K;
		scanf("%d%d%d", &L, &R, &K);
		L--;

		int left = 0, right = N-1;
		while(left <= right)
		{
			int mid = (left + right) / 2;
			int k = 0;
			for(int i=idx(L); i * DIV < R && k <= K; i++)
			{
				if(i * DIV >= L && i * DIV + DIV <= R)
				{
					k += upper_bound(b[i].begin(), b[i].end(), make_pair(a[mid], N)) - b[i].begin();
					continue;
				}
				for(size_t j=0; j < b[i].size() && k <= K; j++)
					if(b[i][j].second >= L && b[i][j].second < R && b[i][j].first <= a[mid])
						k++;
			}

			if(k >= K)
				right = mid - 1;
			else
				left = mid + 1;
		}
		printf("%d\n", a[left]);
	}
	return 0;
}