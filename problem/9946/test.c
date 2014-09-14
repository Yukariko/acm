#include <string.h>
main()
{
  int i;
  char a[1001];
  char b[1001];
  for(i=1;;i++)
  {
    int alen=strlen(gets(a));
    int blen=strlen(gets(b));
    if(strcmp(a,"END")==0)break;
    qsort(a,alen,1,strcmp);
    qsort(b,blen,1,strcmp);
    printf("Case %d: %s\n",i,strcmp(a,b)?"different":"same");
  }
}
