#include <bits/stdc++.h>

using namespace std;

int a[1<<20];
int K;

void merge(int *a, int hN, int N)
{
	vector<int> b(N);
	int i=0, j=hN, k=0;
	while(i < hN && j < N)
	{
		while(i < hN && a[i] < a[j])
		{
			b[k++] = a[i];
			i++;
		}
		b[k++] = a[j];
		j++;
	}

	while(i < hN)
	{
		b[k++] = a[i];
		i++;
	}

	while(j < N)
	{
		b[k++] = a[j];
		j++;
	}

	i=0;
	while(i < N)
	{
		a[i] = b[i];
		i++;
	}
}

void merge_sort(int *a, int N, int D)
{
	if(N > 1)
	{
		int hN = N / 2;
		merge_sort(a, hN, D * 2);
		merge_sort(a + hN, N - hN, D * 2);
		merge(a, hN, N);
		if(D == K)
			for(int i=0; i < N; i++)
				printf("%d ", a[i]);
	}
}

int main()
{
	int N;
	scanf("%d",&N);

	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	scanf("%d",&K);

	merge_sort(a, N, 1);
	return 0;
}