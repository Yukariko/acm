#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);
	while(T--)
	{
		string s;
		getline(cin, s);

		int check = 0;
		for(int i=0; s[i]; i++)
			if(isalpha(s[i]))
				check |= 1 << ((s[i]|32) - 'a');

		if(check == (1 << 26) - 1)
			puts("pangram");
		else
		{
			printf("missing ");
			for(int i=0; i < 26; i++)
				if(!(check & (1 << i)))
					printf("%c",'a' + i);
			puts("");
		}
		
	}
	return 0;
}