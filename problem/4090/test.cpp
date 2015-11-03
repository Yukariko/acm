#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000;

bool isVampire(int a, int b)
{
	int c = a * b;
	int digit[10] = {};
	while(a)
	{
		digit[a % 10]++;
		a /= 10;
	}

	while(b)
	{
		digit[b % 10]++;
		b /= 10;
	}

	while(c)
	{
		digit[c % 10]--;
		c /= 10;
	}

	for(int i=0; i < 10; i++)
		if(digit[i])
			return false;
	return true;
}

int main()
{
	vector<int> vampire;
	for(int i=2; i * i <= 2 * MAX_N; i++)
		for(int j=i+1; i * j <= 2 * MAX_N; j++)
			if(isVampire(i, j))
				vampire.push_back(i * j);

	sort(vampire.begin(), vampire.end());

	int N;
	while(scanf("%d",&N), N)
		printf("%d\n", *lower_bound(vampire.begin(), vampire.end(), N));
	return 0;
}