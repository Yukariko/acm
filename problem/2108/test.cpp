#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());


	int sum = 0;
	for(int i=0; i < N; i++)
		sum += a[i];
	if(sum > 0)
		printf("%d\n", (sum + N/2) / N);
	else
		printf("%d\n", (sum - N/2) / N);
	printf("%d\n", a[N/2]);

	vector<int> ans;
	int maxCnt = 1;
	int cnt = 1;
	for(int i=1; i < N; i++)
	{
		if(a[i-1] != a[i])
		{
			if(maxCnt < cnt)
			{
				maxCnt = cnt;
				ans.clear();
				ans.push_back(a[i-1]);
			}
			else if(maxCnt == cnt)
				ans.push_back(a[i-1]);
			cnt = 0;
		}
		cnt++;
	}

	if(maxCnt < cnt)
	{
		maxCnt = cnt;
		ans.clear();
		ans.push_back(a[N-1]);
	}
	else if(maxCnt == cnt)
		ans.push_back(a[N-1]);

	printf("%d\n", ans.size() == 1? ans[0]: ans[1]);
	printf("%d", a[N-1] - a[0]);
	return 0;
}