char pub_first[1001][11];
char pub_second[1001][11];
char crypt[1001][11],temp[11];
int plain_index[1001];
int i,j,T,N;
main()
{
  for(scanf("%d",&T);~scanf("%d",&N);puts(""))
  {
    for(i=0;i<N;scanf(" %s",pub_first+i++));
    for(i=0;i<N;scanf(" %s",pub_second+i++));
    for(i=0;i<N;scanf(" %s",crypt+i++));
    for(i=0;i<N;i++)
    {
      for(j=0;j<N;j++)
      {
        if(pub_second[j][0]&&!strcmp(pub_first[i],pub_second[j]))
        {
          plain_index[i]=j;
          pub_second[j][0]=0;
          break;
        }
      }
    }
    for(i=0;i<N;i++)printf("%s ",crypt[plain_index[i]]);
  }
}
