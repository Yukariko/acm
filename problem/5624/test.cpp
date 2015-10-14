#include <bits/stdc++.h>

using namespace std;

	
int main()
{
	int N;
	scanf("%d",&N);

	int a[5001];
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	int b[400001];
	memset(b, -1, sizeof(b));

	for(int i=0; i < N; i++)
	{
		for(int j=i; j < N; j++)
		{
			if(b[a[i] + a[j] + 200000] == -1)
				b[a[i] + a[j] + 200000] = j;
			else	
				b[a[i] + a[j] + 200000] = min(b[a[i] + a[j] + 200000], j);
		}
	}

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < i; j++)
		{
			if(b[a[i] - a[j] + 200000] != -1 && b[a[i] - a[j] + 200000] < i)
			{
				ans++;
				break;
			}
		}
	}

	printf("%d", ans);

	return 0;
}