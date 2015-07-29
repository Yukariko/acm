#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		int cnt = 1;

		priority_queue<int> left, right;
		int mid;

		scanf("%d",&N);
		scanf("%d",&mid);
		printf("%d\n%d ", N / 2 + 1, mid);

		for(int i=1; i < N; i+=2)
		{
			int p,q; 
			scanf("%d%d",&p,&q);

			if(p > mid)
				right.push(-p);
			else
				left.push(p);

			if(q > mid)
				right.push(-q);
			else
				left.push(q);

			if(left.size() < right.size())
			{
				left.push(mid);
				mid = -right.top();
				right.pop();
			}
			else if(left.size() > right.size())
			{
				right.push(-mid);
				mid = left.top();
				left.pop();
			}

			printf("%d ",mid);
			cnt++;
			if(cnt == 10 && i != N-2)
			{
				cnt = 0;
				puts("");
			}
		}
		puts("");
	}

	return 0;
}