#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b)
{
	int ans = 2;
	while(a - b >= 0)
	{
		b = a - b;
		a = a - b;
		ans++;
	}

	return ans;
}

int main()
{
	int N;
	scanf("%d",&N);

	int lo = 0, hi = N;
	while(hi - lo >= 3)
	{
		int m1 = (lo * 2 + hi) / 3;
		int m2 = (lo + hi * 2) / 3;

		int val1 = solve(N, m1);
		int val2 = solve(N, m2);

		if(val1 <= val2)
			lo = m1;
		else if(val1 > val2)
			hi = m2;
	}

	int mval = solve(N, lo);
	for(int i=lo+1; i <= hi; i++)
	{
		int val = solve(N, i);
		if(mval < val)
		{
			mval = val;
			lo = i;
		}
	}

	vector<int> a;
	a.push_back(N);
	a.push_back(lo);
	while(a[a.size()-2] - a[a.size()-1] >= 0)
		a.push_back(a[a.size()-2] - a[a.size()-1]);
	
	printf("%d\n", a.size());
	for(auto &pick : a)
		printf("%d ", pick);
	return 0;
}