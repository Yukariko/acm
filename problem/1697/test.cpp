#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int ans = 0;

	vector<bool> visit(210000, 0);
	queue<int> bfs;
	bfs.push(N);

	visit[N] = true;
	while(!bfs.empty())
	{

		int size = bfs.size();
		while(size--)
		{
			int pos = bfs.front();
			bfs.pop();

			if(pos == K)
			{
				cout << ans;
				return 0;
			}

			if(pos && visit[pos-1] == false)
			{
				bfs.push(pos-1);
				visit[pos-1] = true;
			}
			if(pos < K && visit[pos+1] == false)
			{
				bfs.push(pos+1);
				visit[pos+1] = true;
			}
			if(pos * 2 < 200001 && visit[pos * 2] == false)
			{
				bfs.push(pos * 2);
				visit[pos * 2] = true;
			}
		}

		ans++;
	}

	cout << "Oops";
	return 0;
}