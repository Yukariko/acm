#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	string a;
	while(getline(cin,a))
	{
		for(int i=0; a[i]; i++)
			a[i] |= 32;
		if(a.find("problem") != string::npos)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}