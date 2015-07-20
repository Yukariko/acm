#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[21];
	for(int i=1; i <= 20; i++)
		a[i] = i;

	for(int i=0; i < 10; i++)
	{
		int p,q;
		cin >> p >> q;

		reverse(a+p, a+q+1);
	}

	for(int i=1; i <= 20; i++)
		cout << a[i] << " ";
	return 0;
}