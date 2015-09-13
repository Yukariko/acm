#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		vector<int> s(N);
		for(int i=0; i < N; i++)
			cin >> s[i];

		vector<int> r(N);
		vector<bool> check(N+1, false);

		bool error = false;
		for(int i=N-1; i >= 0; i--)
		{
			int idx = 0;
			int j;
			bool find = false;
			for(j=1; j <= N; j++)
			{
				if(check[j] == false)
				{
					idx++;
					if(idx > s[i])
					{
						find = true;
						break;
					}
				}
			}

			r[i] = j;
			if(!find || j > N || check[j])
			{
				error = true;
				break;
			}
			check[j] = true;
		}

		if(error)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for(int i=0; i < N; i++)
			cout << r[i] << " ";
		cout << '\n';
	}
	return 0;
}