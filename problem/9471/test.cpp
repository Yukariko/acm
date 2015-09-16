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
		int N, M;
		cin >> N >> M;

		int f1=1, f2=1;
		int ans = 2;
		while(f1 + f2 != 1)
		{
			ans++;
			f1 = (f1 + f2) % M;
			f2 = f1 - f2;
			if(f2 < 0)
				f2 += M;
		}

		cout << N << " " << ans << '\n';
	}
	return 0;
}