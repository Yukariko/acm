#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	string ans;

	while(N)
	{
		ans += '0' + N % 2;
		N /= 2;
	}

	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}