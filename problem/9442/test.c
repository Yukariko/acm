char alpha[27];
char sort[27];
cmp(char *a,char *b)
{
  char p[31]={},q[31]={};
  int i;
  for(i=0;a[i];i++)
  {
    p[i]=sort[a[i]-'A']+'A';
  }
  for(i=0;b[i];i++)
  {
    q[i]=sort[b[i]-'A']+'A';
  }
  return strcmp(p,q);
}
main()
{
  int t;
  int n;
  char a[21][31];
  for(t=1;scanf("%d",&n),n;t++)
  {
    scanf(" %s ",alpha);
    int i;
    for(i=0;alpha[i];i++)sort[alpha[i]-'A']=i;
    for(i=0;i<n;i++)gets(a[i]);
    qsort(a,n,31,cmp);
    printf("year %d\n",t);
    for(i=0;i<n;i++)puts(a[i]);
  }
}
