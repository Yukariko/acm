main()
{
  int n;
  scanf("%d ",&n);
  char a[101][15]={};
  char b[15];
  int i,j;
  for(i=0;i<n;i++)
  {
    int len=strlen(gets(b));
    for(j=0;j<i;j++)
    {
      if(strcmp(a[j],b)==0)
      {
        return printf("%d %c",len,b[len/2]),0;
      }
    }
    for(j=0;j<len;j++)
    {
      a[i][len-1-j]=b[j];
    }
    if(strcmp(a[i],b)==0)return printf("%d %c",len,b[len/2]),0;
  }
}
