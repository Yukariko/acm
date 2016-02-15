// permutation
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int idx[27];
	memset(idx, -1, sizeof(idx));

	vector<char> alpha;

	char a[11][10];
	for(int i=0; i < N; i++)
	{
		scanf("%s", a[i]);
		for(int j=0; a[i][j]; j++)
			if(idx[a[i][j] - 'A'] == -1)
			{
				idx[a[i][j] - 'A'] = alpha.size();
				alpha.push_back(a[i][j] - 'A');
			}
	}

	sort(alpha.begin(), alpha.end());

	int ans = 0;

	do
	{
		int num[27];
		for(size_t i=0; i < alpha.size(); i++)
			num[alpha[i]] = 9 - i;

		int cur = 0;
		for(int i=0; i < N; i++)
		{
			int n = 0;
			for(int j=0; a[i][j]; j++)
				n = n * 10 + num[a[i][j]-'A'];
			cur += n;
		}
		ans = max(ans, cur);
	} while(next_permutation(alpha.begin(), alpha.end()));

	printf("%d", ans);
	return 0;
}