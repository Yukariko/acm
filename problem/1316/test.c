main()
{
  int n,s=0;
  for(scanf("%d ",&n);n--;)
  {
    char a[101];
    char check[26]={};
    gets(a);
    int i,t=a[0];
    check[t-'a']=1;
    for(i=1;a[i];i++)
    {
      if(t!=a[i])
      {
        t=a[i];
        if(check[t-'a'])break;
        check[t-'a']=1;
      }
    }
    if(a[i]==0)s++;
  }
  printf("%d",s);
}
