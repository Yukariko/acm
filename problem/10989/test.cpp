#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	int a[10001] = {};
	while(N--)
	{
		int n;
		scanf("%d",&n);
		a[n]++;
	}

	for(int i=1; i <= 10000; i++)
		while(a[i]--)
			printf("%d\n",i);
	return 0;
}