#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	printf("%d", N % 2 || !M? N: 1);
	return 0;
}