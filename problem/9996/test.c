main()
{
  int n;
  scanf("%d ",&n);
  char pattern[101];
  int len=strlen(gets(pattern));
  int i,j,wild;
  for(i=0;pattern[i]!='*';i++);
  wild=i;
  pattern[i]=0;
  for(i=0;i<n;i++)
  {
    char a[101];
    int alen=strlen(gets(a));
    if(strncmp(a,pattern,wild)==0)
    {
      if(alen-(len-wild-1)>=wild&&strcmp(a+alen-(len-wild-1),pattern+wild+1)==0)
      {
        puts("DA");
        continue;
      }
    }
    puts("NE");
  }
}
