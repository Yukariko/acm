#include <bits/stdc++.h>

using namespace std;

const int tok = 1000000;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> a(N), b(N);
	vector<int> checkX(2000001, 0), checkY(2000001, 0);

	int leftX = 0, leftY = 0;

	for(int i=0; i < N; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		checkX[a[i] + tok]++;
		checkY[b[i] + tok]++;
		if(a[i] < 0)
			leftX++;

		if(b[i] < 0)
			leftY++;
	}

	int y = 0, x = 0;

	long long ans = 0;
	for(int i=0; i < N; i++)
		ans += abs(a[i] - x) + abs(b[i] - y);

	for(int i=0; i < M; i++)
	{
		char cmd;
		scanf(" %c", &cmd);


		if(cmd == 'S')
		{
			leftY += checkY[y + tok];
			y++;
			ans += leftY - (N - leftY);
		}
		else if(cmd == 'J')
		{
			ans -= leftY - (N - leftY);
			leftY -= checkY[y - 1 + tok];
			y--;
		}
		else if(cmd == 'I')
		{
			leftX += checkX[x + tok];
			x++;
			ans += leftX - (N - leftX);
		}
		else
		{
			ans -= leftX - (N - leftX);
			leftX -= checkX[x - 1 + tok];
			x--;
		}

		printf("%lld\n", ans);
	}

	return 0;
}