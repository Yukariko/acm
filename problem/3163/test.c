typedef struct Ant{ int len,pos,no; } Ant;
cmp(Ant *p, Ant *q)
{
  return p->len > q->len ? 1: p->len < q->len ? -1: 0; 
}
Ant ant[100001];
Ant sort_ant[100001];
main()
{
  int T;
  for(scanf("%d",&T);T--;)
  {
    int N,L,K;
    int i,res;
    scanf("%d%d%d",&N,&L,&K);
    for(i=0;i<N;i++)
    {
      scanf("%d%d",&ant[i].pos,&ant[i].no);
      ant[i].len = ant[i].no > 0? L - ant[i].pos : ant[i].pos;
      sort_ant[i] = ant[i];
    }
    qsort(sort_ant,N,sizeof(Ant),cmp);

    int start, end;
    start = 0;
    end = N-1;

    for(i=0;i<K;i++)
    {
      int pick, pick2 = -1;
      if(sort_ant[i].no > 0) pick = end--;
      else pick = start++;
      if(((i==K-1 && K != N) || i==K-2) && sort_ant[i].len == sort_ant[i+1].len)
      {
        if(sort_ant[i+1].no > 0) pick2 = end--;
        else pick2 = start++;
        if(i == K-1) res = ant[pick].no < ant[pick2].no ? ant[pick].no : ant[pick2].no;
        else res = ant[pick].no < ant[pick2].no ? ant[pick2].no : ant[pick].no;
        break;
      }
      res = ant[pick].no;
    }
    printf("%d\n",res);
  }
}
