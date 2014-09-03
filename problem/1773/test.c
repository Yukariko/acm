int a[2000001];
main()
{
  int n,c;
  scanf("%d%d",&n,&c);
  int i,j,s=0;
  int p;
  for(i=0;i<n;i++)
  {
    scanf("%d",&p);
    for(j=p;j<=c;j+=p)if(!a[j]){a[j]=1;s++;}
  }
  printf("%d",s);
}
