#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	if(N < 4)
	{
		printf("%d", N);
		return 0;
	}
		
	int ans = 1;
	while(N)
	{
		int tok;
		if(N > 4)
			tok = 3;
		else
			tok = N;

		ans = (ans * tok) % 10007;
		N -= tok;
	}

	printf("%d", ans);
	return 0;
}