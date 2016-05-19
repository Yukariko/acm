#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int>& a)
{
	int N = a.size();
	vector<int> b;
	for(int i=0; i < N; i++)
	{
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		if(it == b.end())
			b.push_back(a[i]);
		else
			*it = a[i];
	}

	return b.size();
}

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
			scanf("%d", &a[i]);

		printf("%d\n", lis(a));
	}	
	return 0;
}