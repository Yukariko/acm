#include <stdio.h>
#include <string.h>

int main()
{
	int R,C;
	char a[21][21];
	char word[421][21];
	int wordCount = 0;
	
	scanf("%d%d ",&R,&C);
	for(int i=0;i<R;i++)
		gets(a[i]);
	
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(a[i][j] == '#') continue; 
			if((i == 0 || a[i-1][j] == '#') && !(i == R-1 || a[i+1][j] == '#' ) )
			{
				int p = 0;
				for(int k=i; k < R && a[k][j] != '#'; k++)
				{
					word[wordCount][p++] = a[k][j];
				}
				word[wordCount++][p] = 0;
			}
			if((j == 0 || a[i][j-1] == '#') && !(j == C-1 || a[i][j+1] == '#' ))
			{
				int p = 0;
				for(int k=j; k < C && a[i][k] != '#'; k++)
				{
					word[wordCount][p++] = a[i][k];
				}
				word[wordCount++][p] = 0;	
			}
		}
	}
	qsort(word,wordCount,21,strcmp);
	puts(word[0]);
		
	return 0;   
}
