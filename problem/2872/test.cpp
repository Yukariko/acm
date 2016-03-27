#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		int j=i+1;
		int sel = -1;
		while(a[i] > a[j])
		{
			sel = max(sel, a[j]);
			j++;
		}
		ans = max(ans, sel);
		i = j-1;
	}

	printf("%d", ans);
	return 0;
}