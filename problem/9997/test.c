main()
{
  int n;
  char word[26][101];
  char alpha[26][26]={};
  scanf("%d ",&n);
  int i,j,k,s;
  for(i=0;i<n;i++)
  {
    gets(word[i]);
    for(j=0;word[i][j];j++)alpha[i][word[i][j]-'a']++;
  }
  for(s=i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      for(k=0;k<26;k++)
      {
        if(!alpha[i][k]&&!alpha[j][k])
        {
          break;
        }
      }
      if(k==26)s++;
    }
  }
  printf("%d",s);
}
