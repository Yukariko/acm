typedef struct Ant{ int len,pos; char no; } Ant;
cmp(Ant *p, Ant *q)
{
  return p->len > q->len ? 1: p->len < q->len ? -1: 0; 
}
cmp2(Ant *p, Ant *q)
{
  return p->pos > q->pos ? 1: p->pos < q->pos ? -1: 0;
}
Ant ant[100001];
Ant sort_ant[100001];
main()
{
  int L,N;
  for(;~scanf("%d%d",&L,&N);)
  {
    int i,res,res2;
    for(i=0;i<N;i++)
    {
      ant[i].no = 0;
      scanf(" %d %c",&ant[i].pos,&ant[i].no);
      ant[i].no = ant[i].no == 'R'? 1: -1;
      ant[i].len = ant[i].no > 0? L - ant[i].pos : ant[i].pos;
      sort_ant[i] = ant[i];
    }
    
    qsort(sort_ant,N,sizeof(Ant),cmp);
    qsort(ant,N,sizeof(Ant),cmp2);
    
    int start, end;
    start = 0;
    end = N-1;
    
    for(i=0;i<N;i++)
    {
      int pick, pick2 = -1;
      if(sort_ant[i].no > 0) pick = end--;
      else pick = start++;
      if(i==N-2 && sort_ant[i].len == sort_ant[i+1].len)
      {
        if(sort_ant[i+1].no > 0) pick2 = end--;
        else pick2 = start++;
        
        res = ant[pick].pos < ant[pick2].pos? ant[pick].pos: ant[pick2].pos;
        res2 = ant[pick].pos < ant[pick2].pos? ant[pick2].pos: ant[pick].pos;
        printf("The last ant will fall down in %d seconds - started at %d and %d.\n",sort_ant[i].len,res,res2);
        break;
      }
      res = ant[pick].pos;
    }
    if(i==N)printf("The last ant will fall down in %d seconds - started at %d.\n",sort_ant[N-1].len,res);
  }
}
