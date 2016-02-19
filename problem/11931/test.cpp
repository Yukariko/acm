#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end(), greater<int>());

	for(int i=0; i < N; i++)
		printf("%d\n", a[i]);
	return 0;
}