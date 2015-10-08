#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	for(int i=1; i < N; i++)
		if(a[i-1] > a[i])
			return puts("no");
	puts("yes");
	return 0;
}