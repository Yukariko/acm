#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d%*c",&T);
	for(;T--;)
	{
		char a[1001];
		int len = strlen(gets(a));

		int N;
		scanf("%d ",&N);

		int pos=0;
		for(;N--;)
		{
			int p;
			scanf("%d",&p);
			pos = (pos + p + len) % len;
			putchar(a[pos]);
		}
		puts("");
		scanf("%*c");
	}
	return 0;
}