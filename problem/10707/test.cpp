#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A,B,C,D,P;
	cin >> A >> B >> C >> D >> P;

	cout << min(A*P, B + (C<P?(P-C)*D:0));

	return 0;
}