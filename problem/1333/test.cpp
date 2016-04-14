#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, L, D;
	scanf("%d%d%d", &N, &L, &D);

	int t = 0;
	for(int i=0; i < N; i++)
	{
		t += L;
		if((t - 1) / D < (t + 4) / D)
		{
			printf("%d", (t + D - 1) / D * D);
			return 0;
		}
		t += 5;
	}
	t -= 5;
	printf("%d", (t + D - 1) / D * D);
	return 0;
}