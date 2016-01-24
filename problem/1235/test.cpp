#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	char a[1001][101];
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int len = strlen(a[0]);

	bool complete[1001] = {};
	int check = 0;
	int ans = 1;
	for(int i=len-1; i >= 0; i--)
	{
		for(int j=0; j < N; j++)
		{
			if(complete[j])
				continue;

			bool find = false;
			for(int k=0; k < N; k++)
			{
				if(j == k || complete[k])
					continue;
				if(strcmp(a[j]+i, a[k]+i) == 0)
				{
					find = true;
					break;
				}
			}
			if(!find)
			{
				complete[j] = true;
				check++;
			}
		}
		if(check == N)
			break;
		ans++;
	}

	printf("%d", ans);
	return 0;
}