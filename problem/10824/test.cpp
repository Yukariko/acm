#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	long long a,b,c,d;
	cin >> a >> b >> c >> d;

	long long sA,sB;

	char s[101];
	sprintf(s, "%lld%lld %lld%lld", a,b,c,d);
	sscanf(s, "%lld %lld",&sA,&sB);

	cout << sA + sB;

	return 0;
}