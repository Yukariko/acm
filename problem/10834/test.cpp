#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int turn = 0;
	int accel = 1;

	while(N--)
	{
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);

		accel = accel * B / A;

		if(C == 1)
			turn = !turn;
	}

	printf("%d %d", turn, accel);
	return 0;
}