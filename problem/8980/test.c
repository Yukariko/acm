#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
typedef struct SendBox{ int start,end,nBox; } SendBox;
cmp(SendBox *p,SendBox *q)
{
  if(p->start != q->start)
  {
    return p->start > q->start? 1: -1;
  }
  return p->end > q->end ? 1: p->end < q->end ? -1: 0;
}

int rsv[2001][2001];
int rcvCnt[2001];
int sndCnt[2001];
int curCnt[2001];

main()
{
  int N,C,M;
  int i,j,k;
  
  scanf("%d%d%d",&N,&C,&M);
  
  for(i=0;i<M;i++)
  {
    int start,end,nBox;
    scanf("%d%d%d",&start,&end,&nBox);
    rsv[end][start]=nBox;
    rcvCnt[end]+=nBox;
    sndCnt[start]+=nBox;
  }
  for(i=1;i<=N;i++)
  {
    rcvCnt[i]=MIN(rcvCnt[i],C);
    sndCnt[i]=MIN(sndCnt[i],C);
  }
  
  int res=0;
  
  for(i=2;i<=N;i++)
  {
    int rcv=0,cur;
    for(j=1;j<i;j++)
    {
      if(rsv[i][j])
      {
        cur=MIN(MIN(MIN(rsv[i][j],sndCnt[j]),rcvCnt[i]-rcv),C-rcv-curCnt[j]);
        sndCnt[j]-=cur;
        rcv+=cur;
        curCnt[j]+=rcv;
        printf("%d ",cur);
        if(rcv==rcvCnt[i])break;
      }
    }
    res+=rcv;
    printf("[%d]\n",res);
  }
  printf("%d",res);
}
