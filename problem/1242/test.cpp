#include <iostream>

using namespace std;

int main()
{
	int N,M,K;
	cin >> N >> M >> K;


	int ans = 1;
	int pos = K;
	int num = N;

	while(num)
	{
		int die = ((M - 1) % num) + 1;

		if(die == pos)
			break;

		if(die < pos)
			pos = pos - die;
		else
			pos = num - die + pos;

		num--;
		ans++;
	}

	cout << ans;
	return 0;
}