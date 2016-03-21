#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A, B, C;
	while(scanf("%d%d%d", &A, &B, &C), A | B | C)
	{
		while(C--)
		{
			B = B + A;
			A = B - A;
		}
		printf("%d\n", B);
	}
	return 0;
}