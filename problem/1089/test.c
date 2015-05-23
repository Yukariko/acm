#include <stdio.h>

const char *digit[5][10] = {
	{"###","..#","###","###","#.#","###","###","###","###","###"},
	{"#.#","..#","..#","..#","#.#","#..","#..","..#","#.#","#.#"},
	{"#.#","..#","###","###","###","###","###","..#","###","###"},
	{"#.#","..#","#..","..#","..#","..#","#.#","..#","#.#","..#"},
	{"###","..#","###","###","..#","###","###","..#","###","###"}
};
int N;
char a[6][41];
char ck[11][10];
int found[11];

int check(int pos, int num)
{
	for(int i=0; i < 5; i++)
	{
		for(int j=0; j < 3; j++)
		{
			char tok = digit[i][num][j];
			if(tok != a[i][pos+j] && tok == '.')
				return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d ",&N);
	for(int i=0;i<5;i++)
		gets(a[i]);

	int count = 1;

	for(int i=0;i<N;i++)
	{
		int start = i * 4;
		int find = 0;

		for(int j=0;j<10;j++)
		{
			if(check(start, j))
			{
				ck[i][j] = 1;
				find++;
			}
		}		
		count *= find;
		found[i] = find;
	}

	if(count == 0)
		return puts("-1"),0;

	double ret = 0.0;

	for(int i=0;i<N;i++)
	{
		ret *= 10;
		double t = 0.0;
		for(int j=0;j<10;j++)
		{
			if(ck[i][j])
				t += j;
		}
		ret += t * count / found[i];
	}

	ret /= count;
	printf("%f",ret);
	return 0;
}