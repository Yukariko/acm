int map[5000001];
char turn[5000001];
typedef struct ANT{int p,a,t;}ANT;
main()
{
  int t;
  ANT ant[100001];
  for(scanf("%d",&t);t--;)
  {
    int n,l,k;
    scanf("%d%d%d",&n,&l,&k);
    memset(map,0,4*l);
    int i,j,a,p;
    for(i=0;i<n;i++)
    {
      scanf("%d%d",&a,&p);
      ant[i].p=p;
      ant[i].a=a;
      ant[i].t=a>0?1:-1;
      map[p]=a;
      turn[p]=a>0?1:-1;
    }
  }
}
