#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		vector<int> a(N);

		int total = 0;
		int maximum = 0;
		int count = 0;

		for(int i=0; i < N; i++)
		{
			scanf("%d",&a[i]);
			total += a[i];
			if(a[maximum] < a[i])
			{
				maximum = i;
				count = 1;
			}
			else if(a[maximum] == a[i])
				count++;
		}

		if(count >= 2)
			puts("no winner");
		else
			printf("%s winner %d\n", a[maximum] > total / 2? "majority":"minority", maximum+1);

	}
	return 0;
}