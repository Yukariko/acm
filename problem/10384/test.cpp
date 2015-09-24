#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);

	for(int tc=1; tc <= T; tc++)
	{
		char a[1001];
		gets(a);

		int alpha[26] = {};
		for(int i=0; a[i]; i++)
			if(isalpha(a[i]))
				alpha[(a[i]|32) - 'a']++;

		int ans = 3;
		for(int i=0; i < 26; i++)
			ans = min(ans, alpha[i]);
		if(ans == 3)
			printf("Case %d: Triple pangram!!!\n",tc);
		else if(ans == 2)
			printf("Case %d: Double pangram!!\n",tc);
		else if(ans == 1)
			printf("Case %d: Pangram!\n",tc);
		else
			printf("Case %d: Not a pangram\n",tc);
	}

	return 0;
}