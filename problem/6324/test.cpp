#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		printf("URL #%d\n", tc);

		char a[61];
		scanf("%s", a);

		printf("Protocol = ");
		int i=0;
		while(a[i] != ':')
			putchar(a[i++]);
		i += 3;
		puts("");

		printf("Host     = ");
		while(a[i] && a[i] != ':' && a[i] != '/')
			putchar(a[i++]);
		puts("");

		printf("Port     = ");
		if(a[i] == ':')
		{
			i += 1;
			while(a[i] && a[i] != '/')
				putchar(a[i++]);
		}
		else
			printf("<default>");
		puts("");

		printf("Path     = ");
		if(a[i])
			puts(a + i + 1);
		else
			puts("<default>");

		puts("");
	}
	return 0;
}