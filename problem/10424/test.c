#include <stdio.h>

int main()
{
	int N;
	int a[100001];
	scanf("%d",&N);

	for(int i=1; i <= N; i++)
	{
		int n;
		scanf("%d",&n);
		a[n] = i;
	}

	for(int i=1; i <= N; i++)
		printf("%d\n",i - a[i]);
	return 0;
}