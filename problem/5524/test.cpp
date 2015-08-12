#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	while(N--)
	{
		string a;
		cin >> a;
		for(int i=0; a[i]; i++)
			cout << (char)(a[i] | 32);
		cout << '\n';
	}
	
	return 0;
}