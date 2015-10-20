#include <bits/stdc++.h>

using namespace std;

int N;
deque<int> a;

bool solve()
{
	int pos = 0;
	for(int i=1; i < N; i++)
	{
		pos++;
		if(a[i] - a[i-1] != 1)
			break;
	}
	for(int i=pos+1; i < N; i++)
	{
		reverse(a.begin() + pos, a.begin() + i + 1);

		int t = pos;
		for(int j=t+1; j < N; j++)
		{
			t++;
			if(a[j] - a[j-1] != 1)
				break;
		}

		bool find = true;
		for(int j=t, k=1; j < N; j++, k++)
		{
			if(a[j] != k)
			{
				find = false;
				break;
			}
		}

		if(find)
		{
			printf("%d\n", N-t);
			printf("%d %d\n", pos+1, i+1);
			return true;
		}

		reverse(a.begin() + pos, a.begin() + i + 1);
	}
	return false;
}

int main()
{
	scanf("%d",&N);
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d",&n);
		a.push_back(n);
	}

	for(int i=1; i <= N; i++)
	{
		a.push_front(a.back());
		a.pop_back();

		if(solve())
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}