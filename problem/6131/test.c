main()
{
  int a,b,n,s=0;
  scanf("%d",&n);
  for(b=1;b<=500;b++)
  {
    for(a=b;a<=500;a++)
    {
      if(a*a-b*b==n)s++;
    }
  }
  printf("%d",s);
}
