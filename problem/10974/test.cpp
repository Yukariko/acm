#include <cstring>
#include <cstdio>

int N;
char a[20];
short visit;
void permutation(int pos)
{
	if(pos == N)
	{
		puts(a);
		return;
	}

	for(int i=1; i <= N; i++)
	{
		if((visit & (1 << i)) == 0)
		{
			visit |= 1 << i;
			a[pos*2] = i + '0';
			permutation(pos+1);
			visit &= ~(1 << i);
		}
	}

}

int main()
{
	scanf("%d",&N);
	memset(a, ' ', 2*N);
	permutation(0);
	return 0;
}