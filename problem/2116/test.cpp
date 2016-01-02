#include <bits/stdc++.h>

using namespace std;

// reverse number of dice (ABCDEF)
const int reverse_number[] = {
	5, 3, 4, 1, 2, 0
};

int main()
{
	int N;
	scanf("%d",&N);

	vector<vector<int>> a(N,vector<int>(6));
	for(int i=0; i < N; i++)
		for(int j=0; j < 6; j++)
			scanf("%d",&a[i][j]);

	int ans = 0;

	for(int i=0; i < 6; i++)
	{
		int sum = 0;
		int bottom = a[0][i];
		int up = a[0][reverse_number[i]];

		for(int j=0; j < N; j++)
		{
			int pick = 0;
			for(int k=0; k < 6; k++)
				if(a[j][k] != bottom && a[j][k] != up)
					pick = max(pick, a[j][k]);

			sum += pick;
			if(j == N-1)
				break;

			bottom = up;
			for(int k=0; k < 6; k++)
			{
				if(a[j+1][k] == bottom)
				{
					up = a[j+1][reverse_number[k]];
					break;
				}
			}
		}
		ans = max(ans, sum);
	}

	printf("%d", ans);
	return 0;
}