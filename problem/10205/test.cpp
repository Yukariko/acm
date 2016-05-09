#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);

		char a[51];
		scanf("%s", a);

		int ans = N;
		for(int i=0; a[i]; i++)
			ans += a[i] == 'c'? 1: -1;

		printf("Data Set %d:\n%d\n\n", tc, ans);
	}
	return 0;
}