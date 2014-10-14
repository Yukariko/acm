typedef struct CONDO{int D,C;}CONDO;
cmp(CONDO *p,CONDO *q)
{
  return p->D > q->D ? 1: p->D < q->D ? -1 : p->C > q->C ? 1: p->C < q->C ? -1:0;
}
main()
{
  int N,i;
  CONDO condo[10001];
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d%d",&condo[i].D,&condo[i].C);
  qsort(condo,N,sizeof(CONDO),cmp);
  int res=0,cMin=10001;
  for(i=0;i<N;i++)
  {
    if(cMin>condo[i].C)
    {
      res++;
      cMin=condo[i].C;
    }
  }
  printf("%d",res);
}
