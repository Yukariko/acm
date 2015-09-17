#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int isPalin(const char *a,int len)
{
	int i=len/2;
	int p,q;
	if(len%2==0)
	{
		p=i-1;q=i;
		while(p>=0&&q<len)
			if(a[p--]!=a[q++])
				return 0;
	}
	else
	{
		p=i;q=p;    
		while(p>=0&&q<len)
			if(a[p--]!=a[q++])
				return 0;
	}
	return 1;
}

int main()
{
	string a;
	cin >> a;
	cout << isPalin(a.c_str(), a.length());
	return 0;
}