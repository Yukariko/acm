isPalin(char *a,int i,int j)
{
  int p,q;
  int len=j-i;
  int mid=i+len/2;
  if(len%2==0)
  {
    for(p=mid-1,q=mid;p>=i&&q<j;p--,q++)if(a[p]!=a[q])return 0;
  }
  else
  {
    for(p=mid,q=mid;p>=i&&q<j;p--,q++)if(a[p]!=a[q])return 0;
  }
  return 1;
}
main()
{
  char a[2501];
  int count[2501];
  int len=strlen(gets(a));
  int i,j,k,s=0;
  for(k=i=0;a[i];i++)
  {
    for(j=len;j>i;j--)
    {
      if(isPalin(a,i,j))break;
    }
    count[i]=j-i;
  }
  int max=0,m;
  for(i=1;i<len;i++)
  {
    if(max+count[max]>i)
    {
      if(count[i]>count[max])
      {
        for(j=i-1;j>max;j--)count[j]=0;
        max=i;
      }
      else
      {
        count[i]=0;
      }
    }
    else
    {
      for(j=max;j<i&&j+count[j]<=i;j++);
      max=i;
    }
  }
  for(i=0;i<len;i++)if(count[i]){s++;printf("%d %c %d\n",i,a[i],count[i]);}
  printf("%d",s);
}
