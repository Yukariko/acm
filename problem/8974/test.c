main()
{
  int i,j,t,a,b,s=0;
  scanf("%d%d",&a,&b);
  for(t=i=1;i<=b;)
  {
    for(j=t;j&&i<=b;j--)
    {
      if(a<=i)s+=t;
      i++;
    }
    t++;
  }
  printf("%d",s);
}
