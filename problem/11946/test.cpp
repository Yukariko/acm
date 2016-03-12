#include <bits/stdc++.h>

using namespace std;

bool actable[101][16];
int penalty[101][16];

int main()
{
	int N, M, Q;
	scanf("%d%d%d", &N, &M, &Q);

	vector<pair<int, pair<int, int>>> a(N, make_pair(0, make_pair(0, 0)));
	for(int i=0; i < N; i++)
		a[i].second.second = i+1;

	while(Q--)
	{
		int Time, Team, Prob;
		char answer[4];
		scanf("%d%d%d%s", &Time, &Team, &Prob, answer);

		if(actable[Team][Prob])
			continue;

		bool ac = answer[0] == 'A';
		if(ac)
		{
			actable[Team][Prob] = true;
			a[Team-1].first--;
			a[Team-1].second.first += penalty[Team][Prob] + Time;
		}
		else
		{
			penalty[Team][Prob] += 20;
		}
	}

	sort(a.begin(), a.end());
	for(int i=0; i < N; i++)
		printf("%d %d %d\n", a[i].second.second, -a[i].first, a[i].second.first);
	return 0;
}