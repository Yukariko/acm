#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int i=1; i <= T; i++)
	{
		int a, b, c;
		char op, eq;

		cin >> a >> op >> b >> eq >> c;

		if(op == '+')
		{
			if(a + b == c)
				cout << "Case " << i << ": YES" << endl;
			else
				cout << "Case " << i << ": NO" << endl;
		}
		else if(a - b == c)
			cout << "Case " << i << ": YES" << endl;
		else
			cout << "Case " << i << ": NO" << endl;

	}
	return 0;
}