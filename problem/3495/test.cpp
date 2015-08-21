#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	char a[101][101];
	for(int i=0; i < N; i++)
		cin >> a[i];

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		bool find = false;
		for(int j=0; j < M; j++)
		{
			if(a[i][j] != '.')
			{
				find = !find;
				ans++;
			}
			else if(find)
				ans += 2;
		}
	}

	cout << ans / 2;
	return 0;
}