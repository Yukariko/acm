#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	int M;
	scanf("%d", &M);

	vector<int> b(M);
	for(int i=0; i < M; i++)
		scanf("%d", &b[i]);

	map<int, set<int>> check;
	for(int i=0; i < M; i++)
		check[b[i]].insert(i);

	int minDream = 1001, maxDream = -1;
	for(int depth=1; depth <= M; depth++)
	{
		for(auto& start : check[a[0]])
		{
			bool find = true;
			for(int i=1; i < N; i++)
			{
				if(!check[a[i]].count(start + depth * i))
				{
					find = false;
					break;
				}
			}

			if(find)
			{
				minDream = min(minDream, depth);
				maxDream = max(maxDream, depth);
				break;
			}
		}
	}

	if(minDream == 1001)
		puts("-1");
	else
		printf("%d %d", minDream-1, maxDream-1);
	return 0;
}