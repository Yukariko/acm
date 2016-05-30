#include <bits/stdc++.h>

using namespace std;

char a[1000001];
char b[1000001];


int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s%s", a, b);

		int z2o = 0, o2z = 0;
		for(int i=0; a[i]; i++)
		{
			if(a[i] == '0' && b[i] == '1')
				z2o++;
			else if(a[i] == '1' && b[i] == '0')
				o2z++;
		}

		int ans = abs(z2o - o2z) + min(z2o, o2z);
		printf("%d\n", ans);
	}
	return 0;
}