#include <iostream>
#include <algorithm>

using namespace std;

int N;

char solve(int y, int x)
{
	const int size = 2 * N -1;
	const int mid = N-1;

	y %= size;
	x %= size;

	int sy = abs(y - mid);
	int sx = abs(x - mid);
	if(sy + sx > mid)
		return '.';
	return 'a' + (sy + sx) % 26;
}

int main()
{
	int R1,C1,R2,C2;

	cin >> N;
	cin >> R1 >> C1 >> R2 >> C2;

	for(int i=R1; i <= R2; i++)
	{
		for(int j=C1; j <= C2; j++)
			cout << solve(i,j);
		cout << "\n";
	}
	
	return 0;
}