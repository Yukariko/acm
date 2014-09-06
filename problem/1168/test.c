main()
{
  int n,M;
  int a[100001];
  scanf("%d%d",&n,&M);
  int i,j,k,t;
  for(i=0;i<n;i++)a[i]=i+1;
  printf("<");
  for(i=-1,j=n;j;j--)
  {
    i=(i+M)%j;
    if(j!=1)printf("%d, ",a[i]);
    else printf("%d",a[i]);
    for(k=i;k<j;k++)
    {
      a[k]=a[k+1];
    }
    i--;
  }
  printf(">");
}

