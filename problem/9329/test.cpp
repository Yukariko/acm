#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int N, M;
int a[11][31];
int b[11];
int c[31];

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		cin >> N >> M;

		memset(a, 0, sizeof(a));
		for(int i=0; i < N; i++)
		{
			int num;
			cin >> num;
			for(int j=0; j < num; j++)
			{
				int n;
				cin >> n;
				a[i][n-1] = 1;
			}
			cin >> b[i];
		}

		for(int i=0; i < M; i++)
			cin >> c[i];

		long long ans = 0;
		for(int i=0; i < N; i++)
		{
			int sub = 101;
			for(int j=0; j < M; j++)
				if(a[i][j])
					sub = min(sub, c[j]);

			ans += (long long)sub * b[i];
			for(int j=0; j < M; j++)
				if(a[i][j])
					c[j] -= sub;
		}

		cout << ans << '\n';
	}
	return 0;
}