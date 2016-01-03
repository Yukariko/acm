#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double price;
		scanf("%lf",&price);
		printf("$%.2f\n", price * 0.8);
	}
	return 0;
}