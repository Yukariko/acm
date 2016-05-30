#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	for(int tc=1; scanf("%d ", &N), N; tc++)
	{
		printf("%d\n", tc);

		vector<string> a(N);
		for(int i=0; i < N; i++)
		{
			char b[256];
			gets(b);
			a[i] = b;
		}

		sort(a.begin(), a.end());
		for(int i=0; i < N; i++)
			puts(a[i].c_str());
	}
	return 0;
}