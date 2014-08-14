int n,m;
int o,s,t;
int button[100001];
main()
{
  for(scanf("%d%d",&n,&m);m--;)
  {
    scanf("%d%d%d",&o,&s,&t);
    if(o==0)
    {
      for(;s<=t;s++)button[s]++;
    }
    else
    {
      int k;
      for(k=0;s<=t;s++)k+=button[s]&1;
      printf("%d\n",k);
    }
  }
}
