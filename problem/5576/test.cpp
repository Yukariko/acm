#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w[11];
	int k[11];

	for(int i=0; i < 10; i++)
		scanf("%d",&w[i]);

	for(int i=0; i < 10; i++)
		scanf("%d",&k[i]);

	sort(w, w + 10);
	sort(k, k + 10);

	int ws = w[7] + w[8] + w[9];
	int ks = k[7] + k[8] + k[9];

	printf("%d %d", ws, ks);
	return 0;
}