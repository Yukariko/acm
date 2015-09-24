#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int a, b;
	scanf("%d%d",&a,&b);

	string ans;

	while(1)
	{
		ans += (a % b) + '0';
		a /= b;
		if(a == 0)
			break;
	}

	reverse(ans.begin(), ans.end());
	for(size_t i=0; i < ans.size(); i++)
		if(ans[i] > '9')
			printf("%c",'A' + ans[i] - '9' - 1);
		else
			printf("%c",ans[i]);
	return 0;
}