cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
int a[1000001];
main()
{
  int n,m;
  
  for(;scanf("%d%d",&n,&m),n;)
  {
    int i,j,k,s=0;
    for(i=0;i<n;scanf("%d",a+i++));
    a[i]=100000001;
    for(j=i=0;i<m;i++)
    {
      scanf("%d",&k);
      for(;k>a[j];j++);
      if(a[j]==k)
      {
        s++;
      }
    }
    printf("%d\n",s);
  }
}
