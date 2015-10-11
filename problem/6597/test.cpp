#include <bits/stdc++.h>

using namespace std;

char a[27],b[27];

void post(int pos, int bLeft, int bRight)
{
	int bPos = bLeft;
	while(b[bPos] != a[pos] && b[bPos])
		bPos++;

	if(bPos > bLeft)
		post(pos+1, bLeft, bPos-1);
	if(bPos < bRight)
		post(pos+bPos+1-bLeft, bPos+1, bRight);

	printf("%c",a[pos]);
}

int main()
{
	while(~scanf("%s%s",a,b))
	{
		post(0, 0, strlen(b) - 1);
		puts("");
	}
	return 0;
}