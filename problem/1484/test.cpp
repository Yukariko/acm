#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SQ(n) ((n)*(n))

int main()
{
	int G;
	cin >> G;

	bool find = false;

	for(long long a=1, b=1; SQ(a) - SQ(a-1) <= G; a++)
	{
		while(SQ(a) - SQ(b) > G)
			b++;
		if(SQ(a) - SQ(b) == G)
		{
			find = true;
			cout << a << '\n';
		}
	}

	if(!find)
		cout << -1;

	return 0;
}