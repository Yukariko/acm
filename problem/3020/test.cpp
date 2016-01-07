#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, H;
	scanf("%d%d",&N,&H);

	vector<int> a(N/2), b(N/2);
	for(int i=0; i < N; i+=2)
		scanf("%d%d", &a[i/2], &b[i/2]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int minBreak = N;
	int count = 0;
	for(int i=1; i <= H; i++)
	{
		int curBreak = a.size() - (lower_bound(a.begin(), a.end(), i) - a.begin());
		curBreak += b.end() - upper_bound(b.begin(), b.end(), H-i);
		if(minBreak > curBreak)
		{
			minBreak = curBreak;
			count = 0;
		}
		if(minBreak == curBreak)
			count++;
	}

	printf("%d %d", minBreak, count);
	return 0;
}