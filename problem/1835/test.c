typedef struct Card {int no,val;} Card;
cmp(Card *p,Card *q)
{
  return p->no - q->no;
}
main()
{
  int N;
  Card card[1001];
  int i,j,k,num;

  scanf("%d",&N);
  num = N;
  
  for(i=0;i<N;i++)card[i].no=i;
  for(i=1;i<=N;i++)
  {
    for(j=0;j<=i;j++)
    {
      Card t = card[0];
      for(k=0;k<num-1;k++)card[k]=card[k+1];
      card[num-1]=t;
    }
    card[--num].val = i;
  }
  
  qsort(card,N,sizeof(Card),cmp);
  for(i=0;i<N;i++)printf("%d ",card[i].val); 
}
