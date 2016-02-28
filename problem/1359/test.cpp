#include <bits/stdc++.h>

using namespace std;

int N, M, K;

vector<int> a;

void pickNum(int pos, int pick, int num)
{
	if(pick < 0)
		return;
	if(pos == N)
	{
		if(pick == 0)
			a.push_back(num);
		return;
	}

	pickNum(pos + 1, pick - 1, num * 10 + pos + 1);
	pickNum(pos + 1, pick, num);
}

int bitCount(int n)
{
	int ans = 0;
	while(n)
	{
		ans += n % 2;
		n /= 2;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	pickNum(0, M, 0);

	vector<int> check(a.size(), 0);
	for(size_t i=0; i < a.size(); i++)
		for(int n = a[i]; n; n /= 10)
			check[i] |= 1 << (n % 10);

	int ans = 0;
	for(size_t i=0; i < a.size(); i++)
	{
		for(size_t j=0; j < a.size(); j++)
		{
			int mask = check[i] & check[j];
			if(bitCount(mask) >= K)
				ans++;
		}
	}
	printf("%.10f", (double)ans / (a.size() * a.size()));
	return 0;
}