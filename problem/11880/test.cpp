#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		long long A, B, C;
		scanf("%lld%lld%lld", &A, &B, &C);

		long long a[3] = {A, B, C};
		sort(a, a + 3);

		A = a[0];
		B = a[1];
		C = a[2];
		printf("%lld\n", (A + B) * (A + B) + C * C);
	}
	return 0;
}