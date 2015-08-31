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

		vector<int> a(N);
		for(int i=0; i < N; i++)
			cin >> a[i];

		int ans = 0;
		for(int i=0; i < N; i++)
			for(int j=1; j < N; j++)
				if(a[j] < a[j-1])
					swap(a[j],a[j-1]), ans++;

		cout << ans << '\n';
	}
	return 0;
}