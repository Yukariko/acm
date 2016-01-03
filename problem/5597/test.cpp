#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool check[31] = {};
	for(int i=0; i < 28; i++)
	{
		int n;
		scanf("%d",&n);
		check[n] = true;
	}

	for(int i=1; i <= 30; i++)
		if(check[i] == false)
			printf("%d\n", i);
	return 0;
}