const int ASC = 1;
const int DESC = 2;
typedef struct Pack{
  int *arr;
  int *pack;
  int size;
  int packWidth;
  int packSize;
  int min,max;
}Pack;
Pack *CreatePack(int size,int packWidth)
{
  Pack *p=(Pack *)malloc(sizeof(Pack));
  p->arr=(int *)malloc(sizeof(int) * (size + 1));
  p->pack=(int *)malloc(sizeof(int) * (size / packWidth + 2));
  memset(p->arr,0,sizeof(int) * (size + 1));
  memset(p->pack,0,sizeof(int) * (size / packWidth + 2));
  p->size = size;
  p->packWidth = packWidth;
  p->packSize = size / packWidth + 1;
  p->min = size + 1;
  p->max = 0;
  return p;
}
void pInsert(Pack *p,int pos)
{
  p->arr[pos]++;
  p->pack[pos/p->packWidth]++;
  p->min=p->min > pos ? pos : p->min;
  p->max=p->max < pos ? pos : p->max;
}
void pDelete(Pack *p,int pos)
{
  p->pack[pos/p->packWidth] -= p->arr[pos];
  p->arr[pos]=0;
}
int pFind(Pack *p,int pos)
{
  int i,k,s=0;
  for(i=p->min/p->packWidth;i<=p->packSize;i++)
  {
    if(s + p->pack[i]>=pos)break;
    s += p->pack[i];
  }
  i*=p->packWidth;
  k=i+p->packWidth;
  for(;i<k;i++)
  {
    s+=p->arr[i];
    if(s>=pos)return i;
  }
  return -1;
}
int pCount(Pack *p,int pos, int option)
{
  int i,k=pos/p->packWidth,s=0;
  if(option == ASC)
  {
    for(i=p->min/p->packWidth;i<k;i++)
    {
      s += p->pack[i];
    }
    i*=p->packWidth;
    k=pos;
    for(;i<k;i++)
    {
      s += p->arr[i];
    }
  }
  else
  {
    for(i=p->packSize;i>=k;i--)
    {
      s += p->pack[i];
    }
    i=(i+1)*p->packWidth;
    k=pos;
    for(;i<=k;i++)
    {
      s -= p->arr[i];
    }
  }
  return s;
}
void pFree(Pack *p)
{
  free(p->arr);
  free(p->pack);
  free(p);
}

main()
{
  int T,N;
  for(scanf("%d",&T);T--;)
  {
    int i,k,diff;
    int id[100001]={};
    long long res = 0;
    scanf("%d",&N);
    Pack *pack = CreatePack(N,1000);
    
    for(i=0;i<N;i++)
    {
      scanf("%d",&k);
      id[k]=i;
    }
    for(i=0;i<N;i++)
    {
      scanf("%d",&k);
      diff = id[k]; 
      res+=pCount(pack,id[k],DESC);
      pInsert(pack,id[k]);
    }
    printf("%lld\n",res);
    pFree(pack);
  }
}
