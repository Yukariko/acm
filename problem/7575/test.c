int program[101][1001];
int virus[1001];
int N,K,L;
int i,j;
int answer;
main()
{
  for(scanf("%d%d",&N,&K);i<N;i++)
  {
    scanf("%d",&L);
    for(j=0;j<L;scanf("%d",&program[i][j++]));
  }
  for(i=0;i<K;i++)virus[i]=program[0][i];
  for(i=0;program[0][i+K-1];i++)
  {
    for(j=1;j<N;j++)
    {
      
    }
  }
  puts(answer?"YES":"NO");
}
