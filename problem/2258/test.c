const long long INF = 99987654321;
typedef struct item {
  int W,C;
} ITEM;

int cmp(ITEM *P, ITEM *Q)
{
  return P->C > Q->C? 1: P->C < Q->C? -1:P->W > Q->W ? -1: P->W < Q->W? 1: 0;
}
main()
{
  int N,M;
  ITEM a[100001];
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++)
  {
    scanf("%d%d",&a[i].W,&a[i].C);
  }
  qsort(a,N,8,cmp);
  
  long long S=0,ret=INF;
  for(int i=0;i<N;)
  {
    int P=0,Q=0,R=a[i].C;
    for(;i<N && a[i].C == R; i++)
    {
      P+=a[i].W;
      Q+=a[i].C;
      if(S + P >= M) ret = Q < ret? Q: ret;
    }
    S+=P;
  }
  printf("%lld",ret==INF?-1:ret);
}
