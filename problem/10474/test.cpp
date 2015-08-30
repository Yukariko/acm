#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int P, Q;
	while(cin >> P >> Q, P)
		cout << P / Q << " " << P % Q << " / " << Q << '\n';
	return 0;
}