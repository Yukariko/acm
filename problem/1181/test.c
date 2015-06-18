#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct WORDBOOK{
	int len;
	char word[51];
};

struct WORDBOOK wb[20001];

int cmp(struct WORDBOOK *a,struct WORDBOOK *b)
{
	return a->len > b->len?1:a->len < b->len?-1:strcmp(a->word,b->word);
}

int main()
{
	int N;
	scanf("%d ",&N);
	for(int i=0;i<N;i++)
	{
		gets(wb[i].word);
		wb[i].len=strlen(wb[i].word);
	}
	
	qsort(wb,N,sizeof(struct WORDBOOK),cmp);
	
	int temp = 0;
	for(int i=1;i<=N;i++)
	{
		if(strcmp(wb[temp].word,wb[i].word))
		{
			puts(wb[temp].word);
			temp=i;
		}
	}
	
	return 0;
}
