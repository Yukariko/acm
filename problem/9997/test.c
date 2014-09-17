int n;
char word[26][101];
char alpha[26];
int visit[26];
int count;
f(p,c)
{
  if(c==0){count++;}
  int i,j,t;
  for(i=p;i<n;i++)
  {
    t=0;
    for(j=0;word[i][j];j++)
    {
      t+=alpha[word[i][j]]++==0;
    }
    visit[i]=1;
    f(i+1,c-t);
    visit[i]=0;
    for(j=0;word[i][j];j++)
    {
      alpha[word[i][j]]--;
    }
  }
}
main()
{
  scanf("%d ",&n);
  int i,j,k,s;
  for(i=0;i<n;i++)
  {
    gets(word[i]);
  }
  f(0,26);
  printf("%d",count);
}
