#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		vector<string> a;
		for(int i=0; i < N; i++)
		{
			char buf[256];
			scanf("%s", buf);
			a.push_back(buf);
		}

		int b[21];
		for(int i=0; i < N; i++)
			b[i] = i;

		bool mark[21] = {};
		bool mark2[21] = {};
		while(M--)
		{
			int p, q;
			scanf("%d%d",&p,&q);
			p--;q--;
			b[q] = p;
			mark[q] = true;
			mark2[p] = true;
		}


		for(int i=0; i < N; i++)
		{
			if(mark[i])
				printf("%s ", a[b[i]].c_str());
			else
			{
				for(int j=0; j < N; j++)
					if(mark2[j] == false)
					{
						printf("%s ", a[j].c_str());
						mark2[j] = true;
						break;
					}
			}
		}
		puts("");
	}
	return 0;
}