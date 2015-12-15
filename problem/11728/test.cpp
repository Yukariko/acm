#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	vector<int> a(N), b(M);

	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	for(int i=0; i < M; i++)
		scanf("%d",&b[i]);

	int i=0, j=0;
	while(i < N && j < M)
	{
		while(i < N && a[i] < b[j])
		{
			printf("%d ", a[i]);		
			i++;
		}
		printf("%d ", b[j]);
		j++;
	}

	while(i < N)
	{
		printf("%d ", a[i]);
		i++;
	}

	while(j < M)
	{
		printf("%d ", b[j]);
		j++;
	}
	return 0;
}