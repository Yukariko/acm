main()
{
  int n,a[4]={0};
  int x,y,t;
  a[1]=1;
  
  for(scanf("%d",&n);n--;)
  {
    scanf("%d%d",&x,&y);
    t=a[x];a[x]=a[y];a[y]=t;
  }
  printf("%d",a[1]?1:a[2]?2:a[3]?3:-1);
}
