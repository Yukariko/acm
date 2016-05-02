#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	char a[101][101];
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int ans = 0;
	for(int i=N-1; i >= 0; i--)
		for(int j=M-1; j >= 0; j--)
			if(a[i][j] == '1')
			{
				ans++;
				for(int p=0; p <= i; p++)
					for(int q=0; q <= j; q++)
						a[p][q] = a[p][q] == '1'? '0': '1';
			}

	printf("%d", ans);
	return 0;
}