main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    printf("%d\n",(n%h==0?h:n%h)*100+(n+h-1)/h);
  }
}
