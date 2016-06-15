#include <bits/stdc++.h>

using namespace std;

const char *shape = "PKHT";

int main()
{
	char a[4];
	int b[4] = {};
	set<string> ck;
	while(~scanf("%3s", a))
	{
		if(ck.count(a))
		{
			puts("GRESKA");
			return 0;
		}
		ck.insert(a);

		for(int i=0; shape[i]; i++)
			if(a[0] == shape[i])
				b[i]++;
	}

	for(int i=0; i < 4; i++)
		printf("%d ", 13 - b[i]);
	return 0;
}