#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int>& a)
{
	int N = a.size();
	vector<int> b;

	for(auto &n : a)
	{
		auto lo = lower_bound(b.begin(), b.end(), n);
		if(lo == b.end())
			b.push_back(n);
		else
			*lo = n;
	}
	return b.size();
}

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

    reverse(a.begin(), a.end());
    
	printf("%d",lis(a));
	return 0;
}