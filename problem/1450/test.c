int N,C;
int W[31];
long long res[31];
int cmp(int *a,int *b)
{
  return *a > *b? -1: *a < *b? 1 : 0; 
}

int solve(int pos,int w)
{
  if(pos == N) return 1;
  if(res[pos] <= w) return 1<<(N-pos);
  return (W[pos] <= w ? solve(pos+1, w - W[pos]) : 0) + solve(pos+1,w);
}

main()
{
  scanf("%d%d",&N,&C);
  for(int i=0;i<N;i++)scanf("%d",W+i);
  qsort(W,N,4,cmp);
  for(int i=0;i<N;i++)res[0]+=W[i];
  for(int i=1;i<N;i++)res[i]=res[i-1] - W[i-1];
  printf("%d",solve(0,C));
}
