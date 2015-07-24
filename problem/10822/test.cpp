#include <iostream>

using namespace std;

int main()
{
	int ans = 0;
	int N;
	char c;

	while(1)
	{
		cin >> N >> c;
		ans += N;
		if(cin.eof())
			break;
	}
	cout << ans;
}