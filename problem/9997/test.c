int n;
int test[26];
int visit[26];
int count;
f(p,c)
{
  if(c==67108863)count++;
  for(int i=p;i<n;i++)
  {
    visit[i]=1;
    f(i+1,c|test[i]);
    visit[i]=0;
  }
}
main()
{
  scanf("%d ",&n);
  for(int i=0;i<n;i++)
  {
    char word[101];
    gets(word);
    for(int j=0;word[j];j++)test[i]|=1<<(word[j]-'a');
  }
  f(0,0);
  printf("%d",count);
}
