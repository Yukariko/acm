#include <bits/stdc++.h>

using namespace std;

const char dial[][5] = {
	" ",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ"
};

int same[127];
int typing[127];

int main()
{
	for(int i=0; i < 9; i++)
		for(int j=0; dial[i][j]; j++)
			typing[dial[i][j]] = j+1, same[dial[i][j]] = i;

	int P, W;
	scanf("%d%d ", &P, &W);

	char a[1001];
	gets(a);

	if(a[0] == 0)
	{
		puts("0");
		return 0;
	}

	int ans = P * typing[a[0]];
	for(int i=1; a[i]; i++)
		ans += P * typing[a[i]] + W * (a[i] != ' ' && same[a[i-1]] == same[a[i]]);

	printf("%d", ans);
	return 0;
}