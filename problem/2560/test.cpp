#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A, B, D, N;
	scanf("%d%d%d%d", &A, &B, &D, &N);

	static int addAdultBug[1000001] = {};
	static int subAdultBug[1000001] = {};
	static int dieBug[1000001] = {};
	addAdultBug[A] = 1;
	subAdultBug[B] = 1;
	dieBug[D] = 1;

	int curBug = 1;
	int curAdultActiveBug = 0;

	for(int i=0; i <= N; i++)
	{
		curAdultActiveBug = (curAdultActiveBug + addAdultBug[i] + 1000) % 1000;
		curAdultActiveBug = (curAdultActiveBug - subAdultBug[i] + 1000) % 1000;

		addAdultBug[i+A] = (addAdultBug[i+A] + curAdultActiveBug + 1000) % 1000;
		subAdultBug[i+B] = (subAdultBug[i+B] + curAdultActiveBug + 1000) % 1000;
		dieBug[i+D] = (dieBug[i+D] + curAdultActiveBug + 1000) % 1000;

		curBug = (curBug + curAdultActiveBug - dieBug[i] + 3000) % 1000;
	} 

	printf("%d", curBug);
	return 0;
}