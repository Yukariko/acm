char a[101],k;
int t,i,j,m,n;
cmp(char *a,char *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
main()
{
  for(scanf("%d ",&t);t--;puts(a))
  {
    m=-1;
    for(i=strlen(gets(a))-1;i>=0;i--)
    {
      for(j=i;j>=0&&a[i]<=a[j];j--);
      if(j>=0&&m<j){m=j;n=i;}
    }
    if(m!=-1)
    {
      for(k=a[n];n>m;n--)a[n]=a[n-1];a[m]=k;
      qsort(a+m+1,strlen(a+m+1),1,cmp);
    }
  }
}
