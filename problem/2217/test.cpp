#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int a[100001];

	cin >> N;
	for(int i=0; i < N; i++)
		cin >> a[i];

	sort(a, a+N);

	long long ret = 0;
	for(int i=0; i < N; i++)
		ret = max(ret, (long long)a[i] * (N-i));

	cout << ret;
	return 0;
}