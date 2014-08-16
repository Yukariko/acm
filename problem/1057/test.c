main()
{
  int n,a,b,i;
  scanf("%d%d%d",&n,&a,&b);
  for(i=1;n;n/=2,i++)
  {
    a=a-a/2;
    b=b-b/2;
    if(a==b)break;
  }
  printf("%d",i);
}
