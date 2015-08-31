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

	for(int tc=1;cin >> N, N;tc++)
	{
		int N1 = N * 3;
		int N2 = N1 % 2? (N1+1) /2 : N1 / 2;
		int N3 = 3 * N2;
		int N4 = N3 / 9;

		if(N1 % 2)
			cout << tc << ". odd " << N4 << '\n';
		else
			cout << tc << ". even " << N4 << '\n';
	}
	return 0;
}