#include <bits/stdc++.h>

using namespace std;

const char *says[] = {"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
const char *eq_says[] = {"", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};

int main()
{
	int T;
	scanf("%d", &T);

	for(int testCase = 1; testCase <= T; testCase++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a < b)
			swap(a, b);
			
		printf("Case %d: ", testCase);
		if(a == b)
			printf("%s\n", eq_says[a]);
		else if(a == 6 && b == 5)
			printf("Sheesh Beesh\n");
		else
			printf("%s %s\n", says[a], says[b]);
	}
	return 0;
}