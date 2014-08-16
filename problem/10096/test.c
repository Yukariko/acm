main()
{
  int n;
  char word[26][101];
  int a[26]={0};
  int b[26]={0}
  scanf("%d ",&n);
  int i,j,s;
  for(i=0;i<n;i++)
  {
    gets(word[i]);
    for(j=0;word[i][j];j++)b[word[i][j]-'a']=1;
    for(j=0;j<26;j++)
    {
      a[i]+=b[i];
      b[i]=0;
    }
  }
  for(s=i=0;i<n;i++)
  {
    for(j=0;word[i][j];j++)
    {
      if(a[word[i][j]-'a']<2)break;
    }
    if(!word[i][j])
    {
      puts(word[i]);
      s++;
    }
  }
  for(i=0;i<26&&a[i];i++);
  printf("%d",i==26?1<<s:0);
}
