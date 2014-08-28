main()
{
  int n,w,h;
  for(scanf("%d%d%d",&n,&w,&h);n--;)
  {
    int k;
    scanf("%d",&k);
    if(k*k<=w*w+h*h)puts("DA");
    else puts("NE");
  }
}
