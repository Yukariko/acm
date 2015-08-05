#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	bool d[361] = {};
	for(int h=0; h <= 6; h++)
		for(int m=0; m < 60; m++)
			d[abs(6 * m - (h*30+(m/12)*6))] = true;

	int N;
	while(cin >> N, !cin.eof())
		cout << (d[N]?'Y':'N') << endl;

	return 0;
}