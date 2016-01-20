#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char a[61];
		scanf("%s", a);
		puts(a[strlen(a)-1] & 1? "odd": "even");
	}
	return 0;
}