#include <stdio.h>
#include <stdlib.h>

int N;
int b[100001];
char ck[100001];
int j[100001];
void solve(int left, int right, int bPos)
{
	if(bPos < 0 || bPos >= N || ck[bPos])
		return;
	ck[bPos] = 1;
	printf("%d ",b[bPos]);
	solve(left, j[b[bPos]] - 1, bPos - (right + 1 - j[b[bPos]]));
	solve(j[b[bPos]] + 1, right, bPos - 1);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int p;
		scanf("%d",&p);
		j[p] = i;
	}
	for(int i=0;i<N;i++)
		scanf("%d",b+i);

	solve(0,N-1,N-1);
	return 0;
}
