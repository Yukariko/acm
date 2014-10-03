cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n;
  int a[51];
  for(;~scanf("%d",&n);)
  {
    int i,j;
    for(i=0;i<n;i++)scanf("%d",a+i);
    qsort(a,n,4,cmp);
    
    for(int b=1;b;)
    {
      b=0;
      for(j=1;j<n-1;j++)
      {
        if(a[j-1]+1==a[j])
        {
          int t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;
          b=1;
        }
      }
    }
    
    for(i=0;i<n;i++)printf("%d ",a[i]);
    puts("");
  }
}
