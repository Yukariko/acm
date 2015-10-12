#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	sort(a.begin(), a.end());

	int ans = 0;
	int maxLastScore = 0;
	for(int i=N-1; i >= 0; i--)
	{
		if(a[i] + N >= maxLastScore)
			ans++;
		maxLastScore = max(maxLastScore, a[i] + (N - i));
	}
	printf("%d",ans);
	return 0;
}