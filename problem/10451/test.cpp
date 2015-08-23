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

		vector<int> a(N+1);
		for(int i=1; i <= N; i++)
			cin >> a[i];

		vector<bool> check(N+1, 0);

		int ans = 0;
		for(int i=1; i <= N; i++)
		{
			if(check[i])
				continue;
			for(int k=a[i]; i!=k; k = a[k])
				check[k] = true;
			ans++;
		}

		cout << ans << '\n';
	}
	return 0;
}