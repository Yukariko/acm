#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[1501], b[1501];
	scanf("%s%s", a, b);

	int alen = strlen(a), blen = strlen(b);
	vector<vector<short>> asum(alen + 1), bsum(blen + 1);

	vector<short> cur(26, 0);
	asum[0] = cur;
	for(int i=0; i < alen; i++)
	{
		cur[a[i]-'a']++;
		asum[i+1] = cur;
	}

	fill(cur.begin(), cur.end(), 0);
	bsum[0] = cur;
	for(int i=0; i < blen; i++)
	{
		cur[b[i]-'a']++;
		bsum[i+1] = cur;
	}

	vector<vector<vector<short>>> aset(alen + 1);
	for(int i=0; i < alen; i++)
	{
		for(int j=i+1; j <= alen; j++)
		{
			for(int k=0; k < 26; k++)
				cur[k] = asum[j][k] - asum[i][k];
			aset[j-i].push_back(cur);
		}
	}

	for(int i=1; i <= alen; i++)
		sort(aset[i].begin(), aset[i].end());

	int ans = 0;
	for(int i=0; i < blen; i++)
	{
		for(int j=min(blen, i + alen); j > i && j - i > ans; j--)
		{
			for(int k=0; k < 26; k++)
				cur[k] = bsum[j][k] - bsum[i][k];
			if(binary_search(aset[j-i].begin(), aset[j-i].end(), cur))
			{
				ans = max(ans, j - i);
				break;
			}
		}
	}

	printf("%d", ans);
	return 0;
}