typedef struct Ant{ int len,pos,no; } Ant;
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
  int i;
  scanf("%d%d",&N,&L);
  for(i=0;i<N;i++)
  {
    scanf("%d",&ant[i].pos);
    ant[i].no = i+1;
    ant[i].len = ant[i].pos > 0? L - ant[i].pos : -ant[i].pos;
    sort_ant[i] = ant[i];
    if(ant[i].pos < 0) ant[i].pos = -ant[i].pos;
  }
  
  qsort(sort_ant,N,sizeof(Ant),cmp);
  qsort(ant,N,sizeof(Ant),cmp2);
  
  int start, end, pick;
  start = 0;
  end = N-1;
  
  for(i=0;i<N;i++)
  {
    if(sort_ant[i].pos > 0) pick = end--;
    else pick = start++;
  }
  printf("%d %d",ant[pick].no,sort_ant[N-1].len);
}
