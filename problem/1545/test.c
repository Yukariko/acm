#include <string.h>
isAnti(char *a,int len)
{
  int i;
  for(i=0;i<len/2&&a[i]!=a[len-i-1];i++);
  return i==len/2?1:0;
}
main()
{
  char a[51];
  int len=strlen(gets(a));
  qsort(a,len,1,strcmp);
  int i,j,k,s=0;
  if(len%2==0)
  {
    i=len/2-1;
    j=len/2;
  }
  else
  {
    i=len/2-1;
    j=len/2+1;
  }
  for(;a[j]&&a[i]==a[j];j++,i--)s++;
  for(k=len/2;isAnti(a,len)==0;k++)
  {
    for(i=s-1;i>=0;i--)
    {
      char t;
      int end;
      j=k+i;
      for(end=j+1;end<len&&a[end]==a[j];end++);
      if(end==len)break;
      t=a[j];
      
      a[j]=a[end];
      a[end]=t;
    }
    puts(a);
    if(k+s==len)return puts("-1"),0;
  }
  puts(a);
}
