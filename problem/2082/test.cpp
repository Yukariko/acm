#include <stdio.h>

const char *digit[5][10] = {
	{"###","..#","###","###","#.#","###","###","###","###","###"},
	{"#.#","..#","..#","..#","#.#","#..","#..","..#","#.#","#.#"},
	{"#.#","..#","###","###","###","###","###","..#","###","###"},
	{"#.#","..#","#..","..#","..#","..#","#.#","..#","#.#","..#"},
	{"###","..#","###","###","..#","###","###","..#","###","###"}
};

char a[6][41];

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
	for(int i=0;i<5;i++)
		gets(a[i]);

	for(int i=0;i<4;i++)
	{
		int start = i * 4;
		int find = 0;

		for(int j=0;j<10;j++)
		{
			if(check(start, j))
			{
				find = j;
				break;
			}
		}		
		printf("%d",find);
		if(i==1)
			printf(":");
	}
	return 0;
}