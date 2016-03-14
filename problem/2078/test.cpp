#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A, B;
	scanf("%d%d", &A, &B);

	int L = 0, R = 0;
	while(A != 1 && B != 1)
	{
		if(A > B)
		{
			A -= B;
			L++;
		}
		else
		{
			B -= A;
			R++;
		}
	}

	if(A > 1)
		L += A-1;
	else if(B > 1)
		R += B-1;

	printf("%d %d", L, R);
	return 0;
}