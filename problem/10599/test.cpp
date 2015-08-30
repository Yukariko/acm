#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, d;
	while(cin >> a >> b >> c >> d, a || b || c || d)
		cout << c - b << " " << d - a << endl;
	return 0;
}