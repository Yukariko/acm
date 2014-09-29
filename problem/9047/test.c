#include <string.h>
cmp(char *a,char *b){return *a>*b?1:*a<*b?-1:0;}
cmp2(char *a,char *b){return *a>*b?-1:*a<*b?1:0;}
main()
{
  int t,n;
  char a[5];
  for(scanf("%d ",&t);t--;)
  {
    gets(a);
    int s,i,k;
    for(s=0;atoi(a)!=6174;s++)
    {
      int max,min;
      qsort(a,4,1,cmp);
      min=atoi(a);
      qsort(a,4,1,cmp2);
      max=atoi(a);
      sprintf(a,"%4d",max-min);
      i=0;
      for(k=max-min;k<1000;k*=10)a[i++]='0';
    }
    printf("%d\n",s);
  }
}
