#include <bits/stdc++.h>

using namespace std;

int main()
{

	int T;
	scanf("%d",&T);

	while(T--)
	{
		char a[1001];
		scanf("%s",a);

		int alpha[26] = {};
		for(int i=0; a[i]; i++)
			alpha[a[i]-'A']++;

		int M;
		scanf("%d",&M);

		while(M--)
		{
			char b[101];
			scanf("%s",b);

			int beta[26] = {};
			for(int i=0; b[i]; i++)
				beta[b[i]-'A']++;

			bool ans = true;
			for(int i=0; i < 26; i++)
				if(beta[i] > alpha[i])
					ans = false;
			
			puts(ans? "YES" : "NO");
		}
	}
	return 0;
}