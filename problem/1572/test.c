typedef struct Pack{
  int *arr;
  int *pack;
  int size;
  int packWidth;
  int packSize;
  int min;
}Pack;
Pack *CreatePack(int size,int packWidth)
{
  Pack *p=(Pack *)malloc(sizeof(Pack));
  p->arr=(int *)malloc(sizeof(int) * (size + 1));
  p->pack=(int *)malloc(sizeof(int) * (size / packWidth + 1));
  memset(p->arr,0,sizeof(int) * (size + 1));
  memset(p->pack,0,sizeof(int) * (size / packWidth + 1));
  p->size = size;
  p->packWidth = packWidth;
  p->packSize = size / packWidth;
  p->min = size + 1;
  return p;
}
void pInsert(Pack *p,int pos)
{
  p->arr[pos]++;
  p->pack[pos/p->packWidth]++;
  p->min=p->min > pos ? pos : p->min;
}
void pDelete(Pack *p,int pos,int opt)
{
  if(opt == 0) // all
  {
    p->pack[pos/p->packWidth] -= p->arr[pos];
    p->arr[pos]=0;
  }
  else
  {
    p->pack[pos/p->packWidth]-=opt;
    p->arr[pos]-=opt;
  }
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
int pCount(Pack *p,int pos)
{
  int i,k=pos/p->packWidth,s=0;
  for(i=p->min/p->packWidth;i<k;i++)
  {
    s += p->pack[i];
  }
  i*=p->packWidth;
  k=pos;
  for(;i<k;i++)
  {
    s+=p->arr[i];
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
  int N,K;
  Pack *pack=CreatePack(65536,300);
  int arr[250001];
  int i,k;
  long long res = 0;
  
  scanf("%d%d",&N,&K);
  for(i=0;i<K;i++)
  {
    scanf("%d",&arr[i]);
    pInsert(pack,arr[i]);
  }
  res+=pFind(pack,(K+1)/2);
  for(;i<N;i++)
  {
    scanf("%d",&arr[i]);
    pDelete(pack,arr[i-K],1);
    pInsert(pack,arr[i]);
    res+=pFind(pack,(K+1)/2);
  }
  printf("%lld",res);
}
