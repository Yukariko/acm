#include <bits/stdc++.h>

using namespace std;

int main()
{
	int D, M, Y;
	char a[251];
	while(scanf("%d%d%d ", &D, &M, &Y), D)
	{
		int mod = (D + M + Y) % 25 + 1;
		gets(a);
		for(int i=0; a[i]; i++)
			if(isalpha(a[i]))
				putchar((a[i] - 'a' - mod + 26) % 26 + 'a');
			else
				putchar(a[i]);
		puts("");
	}
	return 0;
}