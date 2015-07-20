#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int ans = 0;
	for(int i=0; i < 5; i++)
	{
		int p;
		cin >> p;
		if(p == N)
			ans++;
	}
	cout << ans;
	return 0;
}