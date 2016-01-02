#include <bits/stdc++.h>

using namespace std;

vector<int> a;

bool visit[10];

void init(int pos, int num)
{
	if(pos == 0)
	{
		a.push_back(num);
		return;
	}

	for(int i=0; i <= 9; i++)
	{
		if(i==0 && num == 0)
			continue;
		if(visit[i] == false)
		{
			visit[i] = true;
			init(pos - 1, num * 10 + i);
			visit[i] = false;
		}
	}
}

int main()
{
	a.push_back(0);
	for(int i=1; i <= 8; i++)
		init(i, 0);

	int N;
	while(scanf("%d",&N), N)
		printf("%d\n", a[N]);
	return 0;
}