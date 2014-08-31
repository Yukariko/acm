char b[10001];
char word[101][10001];
int wLen[101];
isPalin(len)
{
  int i=len/2;
  int p,q;
  if(len%2==0)
  {
    p=i-1;q=i;
    for(;p>=0&&q<len;p--,q++)if(b[p]!=b[q])return 0;
  }
  else
  {
    p=i;q=p;    
    for(;p>=0&&q<len;p--,q++)if(b[p]!=b[q])return 0;
  }
  return 1;
}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d ",&n);
    int i,j;
    for(i=0;i<n;i++)wLen[i]=strlen(gets(word[i]));
    for(i=0;i<n;i++)
    {
      strcpy(b,word[i]);
      for(j=0;j<n;j++)
      {
        if(i!=j)
        {
          strcpy(b+wLen[i],word[j]);
//          printf("[!]%s %s\n",word[i],word[j]);
          if(isPalin(wLen[i]+wLen[j]))
          {
            puts(b);
            break;
          }
        }
      }
      if(j!=n)break;
    }
    if(j==n)puts("0");
  }
}
