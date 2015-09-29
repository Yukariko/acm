#include <bits/stdc++.h>

using namespace std;

// x + 2y = A
// x + y = B

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int A, B;
		scanf("%d%d",&A,&B);
		printf("%d %d\n", 2 * B - A, A - B);
	}
	return 0;
}