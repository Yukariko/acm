#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

vector<int> N(3);
bool visit[201][201][201];

set<int> ans;

void solve(int a, int b, int c)
{
	if(visit[a][b][c])
		return;
	visit[a][b][c] = true;

	if(!a)
		ans.insert(c);

	vector<int> K(3);
	K[0] = a, K[1] = b, K[2] = c;

	for(int i=0; i < 3; i++)
	{
		if(K[i])
		{
			for(int j=0; j < 3; j++)
			{
				if(i==j) continue;

				if(N[j] - K[j] >= K[i])
				{
					K[j] += K[i];
					K[i] -= K[i];
					solve(K[0], K[1], K[2]);
					K[0] = a, K[1] = b, K[2] = c;
				}
				else
				{
					K[i] -= N[j] - K[j];
					K[j] += N[j] - K[j];
					solve(K[0], K[1], K[2]);
					K[0] = a, K[1] = b, K[2] = c;
				}
			}
		}
	}
}

int main()
{	
	cin >> N[0] >> N[1] >> N[2];
	solve(0, 0, N[2]);

	for(set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		cout << *it << " ";
	return 0;
}