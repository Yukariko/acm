#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int M;
	cin >> M;

	int choose[50001] = {};

	int L,R;
	while(cin >> L >> R, L || R)
	{
		if(R < 0 || L > M)
			continue;

		L = max(L, 0);
		R = min(R, M);

		if(L == R)
			continue;

		choose[L] = max(choose[L], R);
	}

	int make = 0;
	int next = 0;
	int ans = 0;
	for(int i=0; i < M; i++)
	{
		if(i > make)
		{
			cout << 0;
			return 0;
		}

		next = max(next, choose[i]);

		if(i == make)
		{
			make = next;
			ans++;
		}
	}

	cout << ans;
	return 0;
}