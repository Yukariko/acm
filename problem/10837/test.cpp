#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int T;
	cin >> T;

	while(T--)
	{
		int P,Q;
		scanf("%d%d",&P,&Q);

		int nr = N - max(P,Q);
		if(P + nr + 1 < Q)
			puts("0");
		else if(Q + nr + 2 < P)
			puts("0");
		else
			puts("1");
	}
	return 0;
}