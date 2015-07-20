#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	while(cin >> N, N)
	{
		++N;
		vector<int> a(N, 0);

		for(int i=1; i < N; i++)
			cin >> a[i];

		sort(a.begin(), a.end());

		int fuel = 200;

		bool find = true;
		for(int i=1; i < N; i++)
		{
			if(a[i] - a[i-1] > fuel)
			{
				find = false;
				break;
			}
		}

		if(!find)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			if((1422 - a[N-1]) * 2 > 200)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << "POSSIBLE" << endl;
		}
	}

	return 0;
}