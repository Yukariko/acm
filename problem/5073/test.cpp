#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A, B, C;
	while(scanf("%d%d%d", &A, &B, &C), A)
	{
		if(A == B && B == C)
			puts("Equilateral");
		else if(A == B || B == C || C == A)
			puts("Isosceles");
		else if(A + B + C - max({A, B, C}) <= max({A, B, C}))
			puts("Invalid");
		else
			puts("Scalene");
	}
	return 0;
}