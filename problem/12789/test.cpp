#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	stack<int> b;

	int order = 1;
	for(int i=0; i < N; i++)
	{
		if(a[i] == order)
		{
			order++;
			continue;
		}

		while(!b.empty() && b.top() == order)
		{
			b.pop();
			order++;
		}

		b.push(a[i]);
	}

	while(!b.empty() && b.top() == order)
	{
		b.pop();
		order++;
	}

	if(order > N)
		puts("Nice");
	else
		puts("Sad");

	return 0;
}