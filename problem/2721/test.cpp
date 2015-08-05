#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int d[302];
	for(int p=1, i=1; p <= 301; p++, i+=p)
		d[p] = i;

	d[0] = 0;
	for(int i=1; i <= 300; i++)
		d[i] = d[i-1] + i * d[i+1];

	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;

		int ans = 0;
		cout << d[N] << endl;
	}

	return 0;
}