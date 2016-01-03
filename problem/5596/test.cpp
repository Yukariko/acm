#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s = 0, t = 0;
	for(int i=0; i < 4; i++)
	{
		int n;
		scanf("%d",&n);
		s += n;
	}

	for(int i=0; i < 4; i++)
	{
		int n;
		scanf("%d",&n);
		t += n;
	}

	printf("%d", max(s, t));
	return 0;
}