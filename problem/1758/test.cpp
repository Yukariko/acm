#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int N;
	int a[100001];

	cin >> N;
	for(int i=0; i < N; i++)
		cin >> a[i];

	sort(a, a + N, greater<int>());

	long long ret = 0;
	for(int i=0; i < N; i++)
	{
		if(a[i] - i < 0)
			break;
		ret += a[i] - i;
	}
	cout << ret;
	return 0;
}