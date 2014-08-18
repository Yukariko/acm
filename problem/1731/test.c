main()
{
  int n;
  int a,b,c,k=0,s;
  scanf("%d",&n);
  scanf("%d%d%d",&a,&b,&c);
  if(b-a==c-b)
  {
    k=1;
    s=b-a;
  }
  if(1.0*b/a==1.0*c/b)
  {
    k=2;
    s=b/a;
  }
  for(n-=3;n--;scanf("%d",&c));
  printf("%d",k==1?c+s:c*s);
}
