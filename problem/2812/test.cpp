#include <bits/stdc++.h>

using namespace std;

char a[500001];

queue<int> b[11];

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	scanf("%s", a);

	K++;

	int idx = 0;
	int last = 0;
	int size = 0;

	while(idx < N)
	{
		while(size < K)
		{
			b[a[idx]-'0'].push(idx);
			idx++;
			size++;
		}

		for(int i=9; i >= 0; i--)
		{
			if(!b[i].empty())
			{
				printf("%d",i);
				last = b[i].front();
				b[i].pop();
				size--;
				break;
			}
		}

		for(int i=0; i < 10; i++)
			while(!b[i].empty() && b[i].front() < last)
				b[i].pop(), size--, K--;
	}

	return 0;
}