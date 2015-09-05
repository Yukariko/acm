#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int a, b;
	while(cin >> a >> b, a || b)
		cout << a + b << '\n';
	return 0;
}