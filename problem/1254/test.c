char a[1001];
char b[2002];
isPalin(len)
{
  int i=len/2;
  if(len%2==0)
  {
    int p,q;
    p=len/2-1;q=len/2;
    for(;p>=0&&q<len;p--,q++)if(b[p]!=b[q])return 0;
  }
  else
  {
    int p,q;
    p=len/2;q=p;    
    for(;p>=0&&q<len;p--,q++)if(b[p]!=b[q])return 0;
  }
  return 1;
}
main()
{
  int len=strlen(gets(a));
  int i,j;
  strcpy(b,a);
  if(isPalin(len)){printf("%d",len);return;}
  for(i=0;i<len-1;i++)
  {
    for(j=i;j>=0;j--)b[len+i-j]=a[j];
    b[len+i+1]=0;
    if(isPalin(len+i+1))
    {
      printf("%d",len+i+1);
      break;
    }
  }
}
