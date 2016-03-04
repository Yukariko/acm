#include <bits/stdc++.h>

using namespace std;

int aN;
int bN;

int a[21];
int b[21];

vector<pair<int, int>> asum, bsum;

void makeNum(int *arr, vector<pair<int, int>>& save, int pos, int num, int mask)
{
	if(pos == -1)
	{
		save.push_back({num, mask});
		return;
	}

	makeNum(arr, save, pos - 1, num + arr[pos], mask * 2 + 1);
	makeNum(arr, save, pos - 1, num, mask * 2);
}


int main()
{
	int N;
	scanf("%d", &N);

	aN = N / 2;
	bN = N - aN;

	for(int i=0; i < aN; i++)
		scanf("%d", &a[i]);

	for(int i=0; i < bN; i++)
		scanf("%d", &b[i]);

	int K;
	scanf("%d", &K);

	makeNum(a, asum, aN-1, 0, 0);
	makeNum(b, bsum, bN-1, 0, 0);

	sort(bsum.begin(), bsum.end());
	for(size_t i=0; i < asum.size(); i++)
	{
		auto lo = lower_bound(bsum.begin(), bsum.end(), make_pair(K - asum[i].first, 0));
		if(lo->first == K - asum[i].first)
		{
			for(int j=0; j < aN; j++)
			{
				putchar("01"[asum[i].second % 2]);
				asum[i].second /= 2;
			}
			for(int j=0; j < bN; j++)
			{
				putchar("01"[lo->second % 2]);
				lo->second /= 2;
			}
			return 0;
		}
	}

	return 0;
}