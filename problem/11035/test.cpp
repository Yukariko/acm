#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	while(~scanf("%d%d", &N, &K))
	{
		vector<bool> numSet(N+1, false);

		int ans = -1;

		for(int i=2; i <= N; i++)
		{
			if(numSet[i] == false)
			{
				K--;
				if(K == 0)
				{
					ans = i;
					break;
				}

				for(int j=i*i; j <= N; j+=i)
				{
					if(numSet[j] == false)
					{
						K--;
						if(K == 0)
						{
							ans = j;
							break;
						}
						numSet[j] = true;
					}
				}

				if(K == 0)
					break;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}