#include <bits/stdc++.h>

using namespace std;

int N;
char a[51][51];
long long b[51];
int c[51];

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			if(strncmp(a[i], a[j], min(strlen(a[i]), strlen(a[j]))) == 0)
				b[i] |= 1LL << j, b[j] |= 1LL << i, c[i]++, c[j]++;

	int ans = N;
	for(int i=0; i < N; i++)
	{
		int maxOverlap = max_element(c, c + N) - c;
		if(!c[maxOverlap])
			break;
		ans--;
		c[maxOverlap] = 0;
		for(int j=0; j < N; j++)
			if(b[maxOverlap] & (1LL << j))
				c[j]--;
	}
	printf("%d", ans);
	return 0;
}