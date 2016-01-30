#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		char a[100001];
		scanf("%s", a);

		int N;
		scanf("%d", &N);

		deque<int> q;
		scanf(" %*c");
		for(int i=0; i < N; i++)
		{
			int n;
			scanf("%d%*c", &n);
			q.push_back(n);
		}
		scanf("%*c");

		bool err = false;
		bool reverse = false;

		for(int i=0; a[i]; i++)
		{
			if(a[i] == 'R')
			{
				reverse = !reverse;
			}
			else
			{
				if(q.empty())
				{
					err = true;
					break;
				}
				if(reverse)
					q.pop_back();
				else
					q.pop_front();
			}
		}

		if(err)
		{
			puts("error");
			continue;
		}

		printf("[");
		while(!q.empty())
		{
			int n;
			if(reverse)
			{
				n = q.back();
				q.pop_back();
			}
			else
			{
				n = q.front();
				q.pop_front();
			}
			printf("%d", n);
			if(!q.empty())
				printf(",");
		}
		puts("]");
	}
	return 0;
}