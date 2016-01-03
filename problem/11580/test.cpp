#include <bits/stdc++.h>

using namespace std;

const char *mark = "SENW";
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main()
{
	bool field[2001][2001] = {};
	int L;
	scanf("%d",&L);

	int ans = 1;
	int y = 0, x = 0;
	field[y + 1000][x + 1000] = true;

	while(L--)
	{
		char c;
		scanf(" %c",&c);

		for(int i=0; mark[i]; i++)
			if(mark[i] == c)
				y += dy[i], x += dx[i];

		if(field[y + 1000][x + 1000] == false)
			ans++, field[y + 1000][x + 1000] = true;
	}

	printf("%d", ans);
	return 0;
}