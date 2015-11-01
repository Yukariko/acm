#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	stack<int> a;
	while(N--)
	{
		int n;
		scanf("%d",&n);
		if(n == 0)
			a.pop();
		else
			a.push(n);
	}

	int ans = 0;
	while(!a.empty())
	{
		ans += a.top();
		a.pop();
	}
	printf("%d", ans);
	return 0;
}