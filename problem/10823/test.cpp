#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int ans = 0;
	int N;
	char c;
	int num = 0;
	while(~(c = getchar()))
	{
		if(c >= '0' && c <= '9')
		{
			num *= 10;
			num += c-'0';
		}
		else if(c == ',')
		{
			ans += num;
			num = 0;
		}
	}
	ans += num;
	cout << ans;
}