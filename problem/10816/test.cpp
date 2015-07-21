#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	int a[500001];
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	sort(a, a + N);

	int M;
	cin >> M;

	while(M--)
	{
		int p;
		scanf("%d",&p);
		printf("%d ",upper_bound(a,a+N,p) - lower_bound(a,a+N,p));
	}
	return 0;
}