#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		ans += B % A;
	}

	cout << ans;
	return 0;
}