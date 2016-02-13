#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ", &T);

	while(T--)
	{
		char a[1001];
		int len = strlen(gets(a));

		for(int i=0; a[i]; i++)
			if(isalpha(a[i]))
				a[i] |= 32;

		bool success = true;
		for(int i=0; i <= len/2; i++)
		{
			if(a[(len-1)/2 - i] != a[len/2 + i])
			{
				success = false;
				break;
			}
		}

		puts(success? "Yes": "No");
	}
	return 0;
}