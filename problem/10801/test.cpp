#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[10];
	int b[10];

	for(int i=0; i < 10; i++)
		cin >> a[i];

	for(int i=0; i < 10; i++)
		cin >> b[i];

	int ans = 0;

	for(int i=0; i < 10; i++)
		if(a[i] > b[i])
			ans++;
		else if(a[i] < b[i])
			ans--;

	cout << (ans > 0? 'A' : ans? 'B': 'D');

	return 0;
}