#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#include <deque>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		deque<int> a(N);
		for(int i=0; i < N; i++)
			cin >> a[i];

		long long ans = 0;

		while(1)
		{
			int irregular = -1;
			for(int i=1; i < N; i++)
			{
				if(a[i] < a[i-1])
				{
					irregular = i;
					break;
				}
			}

			if(irregular == -1)
				break;

			int cnt = 0;
			long long search = 1;
			int sameCnt = 0;
			for(int i=0; a[i] < a[irregular]; i++)
			{
				if(i && a[i] != a[i-1])
				{
					search *= sameCnt + 1;
					sameCnt = 1;
				}
				else
					sameCnt++;
				cnt++;
			}

			search *= sameCnt + 1;
			ans += search;

			int temp = a[irregular];
			a.erase(a.begin() + irregular);
			a.push_front(temp);

			sort(a.begin(), a.begin() + cnt + 2);

		}
		cout << ans << '\n';
	}
	return 0;
}