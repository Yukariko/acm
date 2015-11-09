#include <bits/stdc++.h>

using namespace std;

bool fit(const vector<int>& a, int cut)
{
	int N = a.size();

	int begin = a[0];
	int before = a[0];
	int last = a[N-1];

	for(int i=1; i < N-1; i++)
	{
		if(a[i] - a[i-1] > cut)
			return false;

		if(a[i] - begin <= cut && a[i+1] - begin <= cut)
		{
			int t = begin;
			begin = a[i];
			before = t;
		}
	}

	return last - begin <= cut;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d",&a[i]);

		sort(a.begin(), a.end());

		int start = 0, end = 100001;
		while(start <= end)
		{
			int mid = (start + end) / 2;
			if(fit(a, mid))
				end = mid - 1;
			else
				start = mid + 1;
		}

		printf("%d\n", start);
	}
	return 0;
}