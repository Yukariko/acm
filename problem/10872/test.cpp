#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int ans = 1;
	while(N)
		ans *= N--;
	cout << ans;
	return 0;
}