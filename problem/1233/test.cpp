#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int A,B,C;
	cin >> A >> B >> C;

	int a[100] = {};
	for(int i=1; i <= A; i++)
		for(int j=1; j <= B; j++)
			for(int k=1; k <= C; k++)
				a[i+j+k]++;

	int ans = 0;
	int m = 0;
	for(int i=0; i < 100; i++)
		if(m < a[i])
			m = a[i], ans = i;
	cout << ans;
	return 0;
}