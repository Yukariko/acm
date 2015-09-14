#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[11][11];
int src;

bool visit[11];
int tsp(int here)
{
	bool move = false;
	int ans = 987654321;
	for(int i=0; i < N; i++)
	{
		if(visit[i] == false && a[here][i])
		{
			move = true;
			visit[i] = true;
			ans = min(ans, a[here][i] + tsp(i));
			visit[i] = false;
		}
	}

	if(!move && a[here][src])
		ans = a[here][src];
	return ans;
}

int main()
{
	cin >> N;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			cin >> a[i][j];

	int ans = 987654321;
	for(int i=0; i < N; i++)
	{
		src = i;
		visit[src] = true;
		ans = min(ans, tsp(i));
		visit[src] = false;
	}

	cout << ans;
	return 0;
}