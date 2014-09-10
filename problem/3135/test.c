main()
{
  int a,b;
  int n;
  scanf("%d%d",&a,&b);
  scanf("%d",&n);
  int i,s=abs(a-b),k;
  for(i=0;i<n;i++)
  {
    scanf("%d",&k);
    s=s>abs(k-b)+1?abs(k-b)+1:s;
  }
  printf("%d",s);
}
