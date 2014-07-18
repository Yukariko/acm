#include<string.h>
char nohear[500001][21];
char nosee[21];
char *nohearnosee[500001],*p;
int N,M;
int i,j;
int cmp(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}
main()
{
  scanf("%d%d ",&N,&M);
  for(i=0;i<N;gets(nohear+i++));
  qsort(nohear,N,21,strcmp);
  for(i=0;i<M;i++)
  {
    if(p=bsearch(gets(nosee),nohear,N,21,strcmp))
    {
      nohearnosee[j++]=p;
    }
  }
  qsort(nohearnosee,j,sizeof(char *),cmp);
  printf("%d\n",j);
  for(i=0;i<j;i++)puts(nohearnosee[i]);
}
