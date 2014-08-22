main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j,s=0;
    for(i=1;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
        if((i*i+j*j+m)%(i*j)==0)s++;
      }
    }
    printf("%d\n",s);
  }
}
