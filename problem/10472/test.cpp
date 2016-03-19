#include <bits/stdc++.h>

using namespace std;

const int dy[] = {0, 1, -1, 0, 0};
const int dx[] = {0, 0, 0, 1, -1};

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		char a[3][4];
		for(int i=0; i < 3; i++)
			scanf("%s", a[i]);

		int mask = 0;
		for(int i=0; i < 3; i++)
			for(int j=0; j < 3; j++)
				if(a[i][j] == '*')
					mask |= 1 << (i * 3 + j);

		set<int> check;
		queue<int> bfs;
		check.insert(mask);
		bfs.push(mask);

		int ans = 0;
		while(!bfs.empty())
		{
			int size = bfs.size();
			while(size--)
			{
				int here = bfs.front();
				bfs.pop();

				if(here == 0)
				{
					printf("%d\n", ans);
					bfs = queue<int>();
					break;
				}

				for(int i=0; i < 3; i++)
				{
					for(int j=0; j < 3; j++)
					{
						int there = here;
						for(int d=0; d < 5; d++)
						{
								int ny = i + dy[d];
								int nx = j + dx[d];
								if(ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
									continue;

								there ^= 1 << (ny * 3 + nx);
						}
						if(!check.count(there))
						{
							check.insert(there);
							bfs.push(there);
						}
					}
				}
				
			}
			ans++;
		}

	}
	return 0;
}