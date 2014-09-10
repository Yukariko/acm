char word[17][101];
int len[17];
int graph[17][17];
int visit[17];
int n;
int max;
char tmp[2000];
f(p,s)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(!visit[i]&&graph[p][i]&&word[i][0]==word[i][len[i]-1])
    {
      visit[i]=1;
      s+=len[i];
      p=i;
      i=-1;
    }
  }
  for(i=0;i<n;i++)
  {
    if(!visit[i]&&graph[p][i])
    {
      visit[i]=1;
      f(i,s+len[i]);
      visit[i]=0;
    }
  }
  max=max<s?s:max;
}
main()
{
  int i,j;
  scanf("%d ",&n);
  for(i=0;i<n;i++)
  {
    len[i]=strlen(gets(word[i]));
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i!=j&&word[i][len[i]-1]==word[j][0])
      {
        graph[i][j]=1;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)visit[j]=0;
    visit[i]=1;
    f(i,len[i]);
  }
  printf("%d",max);
}
