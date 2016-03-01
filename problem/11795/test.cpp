#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int A = 0, B = 0, C = 0;
	while(N--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		A += a;
		B += b;
		C += c;

		int minimum = min({A, B, C});
		if(minimum < 30)
			puts("NO");
		else
		{
			printf("%d\n", minimum);
			A -= minimum;
			B -= minimum;
			C -= minimum;
		}
	}
	return 0;
}