cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int a[101][101];
  int b[20000];
  int i,j,p=0;
  int n,k;
  scanf("%d%d",&n,&k);
  for(i=2;i<=n;i++)
  {
    for(j=2;j<=n;j++)
    {
      a[i][j]=i*j;
      b[p++]=i*j;
    }
  }
  qsort(b,p,4,cmp);
  
  puts("---");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%3d ",a[i][j]);
    }
    puts("");
  }
  puts("---");
  for(i=0;i<p;i++)printf("%d %d\n",i+1,b[i]);
}
