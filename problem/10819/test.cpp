#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[9];
bool visit[9];
int sel[9];

int solve(int pos)
{
	if(pos == N)
	{
		int ret = 0;
		for(int i=1; i < N; i++)
			ret += abs(sel[i-1]-sel[i]);
		return ret;
	}

	int ret = 0;

	for(int i=0; i < N; i++)
	{
		if(!visit[i])
		{
			visit[i]=true;
			sel[pos] = a[i];
			ret = max(ret, solve(pos+1));
			visit[i]=false;
		}
	}

	return ret;
}


int main()
{
	cin >> N;
	for(int i=0; i < N; i++)
		cin >> a[i];

	cout << solve(0);
	return 0;
}