cmp(char *a,char *b)
{
  int p,q;
  p=strlen(a);
  q=strlen(b);
  if(p==q)
  {
    int i;
    p=q=0;
    for(i=0;a[i];i++)
    {
      if(a[i]>='0'&&a[i]<='9')p+=a[i]-'0';
      if(b[i]>='0'&&b[i]<='9')q+=b[i]-'0';
    }
    if(p==q)return strcmp(a,b);
    return p-q;
  }
  else
  {
    return p-q;
  }
}
main()
{
  int n;
  char a[1001][51];
  scanf("%d ",&n);
  int i;
  for(i=0;i<n;i++)gets(a[i]);
  qsort(a,n,51,cmp);
  for(i=0;i<n;i++)puts(a[i]);
}
