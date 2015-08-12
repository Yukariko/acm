#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int A=0, B=0;

	while(N--)
	{
		int p, q;
		cin >> p >> q;
		if(p > q)
			A++;
		else if(p < q)
			B++;
	}
	
	cout << A << " " << B;
	return 0;
}