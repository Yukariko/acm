#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for(int i=0; i < N; i++)
	{
		char a[11];
		scanf("%s", a);

		reverse(a, a + M);
		puts(a);
	}
	return 0;
}