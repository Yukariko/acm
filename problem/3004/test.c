main()
{
  int n;
  int s=2,k=2,t=1;
  for(scanf("%d",&n);--n;t--)
  {
    s+=k;
    if(t==0){k++;t=2;}
  }
  printf("%d",s);
}
