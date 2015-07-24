#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int ans = 0;
	int N;
	char a[101];

	gets(a);

	if(strtok(a, ","))
		ans++;

	while(strtok(NULL, ","))
		ans++;
	
	cout << ans;
}