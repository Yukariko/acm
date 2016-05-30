#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[101];
	while(gets(a))
	{
		char b[3][30] = {};

		int cnt = 0;
		int idx[3] = {};
		for(int i=0; a[i]; i++)
		{
			if(a[i] == '+' || a[i] == '=')
				cnt++;
			else
				b[cnt][idx[cnt]++] = a[i];
		}

		for(int i=0; i < 3; i++)
			reverse(b[i], b[i] + idx[i]);

		int p, q, r;
		p = atoi(b[0]);
		q = atoi(b[1]);
		r = atoi(b[2]);

		if(p + q == r)
			puts("True");
		else
			puts("False");
	}
	return 0;
}