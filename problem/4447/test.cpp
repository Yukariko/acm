#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ", &T);

	while(T--)
	{
		char a[26];
		gets(a);

		int g=0, b=0;
		for(int i=0; a[i]; i++)
			if((a[i] | 32) == 'g')
				g++;
			else if((a[i] | 32) == 'b')
				b++;

		printf("%s is %s\n", a, g > b? "GOOD": g < b? "A BADDY": "NEUTRAL");
	}
	return 0;
}