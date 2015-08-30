#include <iostream>

using namespace std;

int main()
{
	int N;
	int tc=1;
	while(cin >> N, N)
	{
		int ans = 0;
		for(int i=5; i <= N; i *= 5)
			ans += N / i;
		cout << "Case #" << tc << ": " << ans << '\n';
		tc++;
	}
	return 0;
}