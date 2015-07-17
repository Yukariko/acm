#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int a[1001];

	cin >> N;
	for(int i=0; i < N; i++)
		cin >> a[i];

	sort(a, a + N);

	int range = 0;

	for(int i=0; i < N; i++)
	{
		if(range + 1 < a[i])
			break;

		range += a[i];
	}

	cout << range+1;

	return 0;
}