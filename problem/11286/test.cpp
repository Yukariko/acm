#include <bits/stdc++.h>

using namespace std;

struct compare
{
	bool operator() (int a, int b)
	{
		if(abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	int N;
	scanf("%d",&N);

	priority_queue<int, vector<int>, compare> pq;
	while(N--)
	{
		int n;
		scanf("%d",&n);

		if(n)
			pq.push(n);
		else if(pq.empty())
			puts("0");
		else
		{
			printf("%d\n", pq.top());
			pq.pop();
		}
	}
	return 0;
}