main()
{
  char cmd;
  int n,s,m=0;
  for(scanf("%d",&s);scanf("%c",&cmd),cmd!=10;)
  {
    if(cmd=='-')m=1;
    scanf("%d",&n);
    if(m)s-=n;
    else s+=n;
  }
  printf("%d",s);
}
