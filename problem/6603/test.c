int K;
int S[14];
int ret[7];
void solve(int depth,int pos)
{
  if(depth == 6)
  {
    for(int i=0;i<6;i++)
    {
      printf("%d ",ret[i]);
    }
    puts("");
    return;
  }
    
  for(int i=pos;i<K;i++)
  {
    ret[depth] = S[i];
    solve(depth+1,i+1);
  }
}
main()
{
  for(;scanf("%d",&K),K;)
  {
    for(int i=0;i<K;i++)
      scanf("%d",S+i);
    solve(0,0);
    puts("");
  }
}
