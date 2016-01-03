#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d ",&N);

	char a[101][101];
	for(int i=0; i < N; i++)
		gets(a[i]);

	scanf("%d",&K);

	if(K == 2)
		for(int i=0; i < N; i++)
			reverse(&a[i][0], &a[i][0] + N);
	else if(K == 3)
		reverse(&a[0], &a[0] + N);

	for(int i=0; i < N; i++)
		puts(a[i]);
	return 0;
}