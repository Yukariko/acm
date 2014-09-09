main()
{
  int n;
  int a[11];
  int b[11];
  int i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  k=0;
  for(i=n-1;i>=0;i--)
  {
    if(a[i]==k)b[k]=i;
    else
    {
      for(j=k+1;j>a[i];j--)b[j]=b[j-1];
      b[a[i]]=i;
    }
    k++;
  }
  for(i=0;i<n;i++)printf("%d ",b[i]+1);
}
