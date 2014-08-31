main()
{
  int m,n,c=0,s=0,t=0;
  scanf("%d%d",&m,&n);
  int i;
  c=n-1;
  for(i=t=0;t<m*n-1;t++)
  {
    if(i==c)
    {
      s++;
      if(s%2)c=m-1-(s-1)/2;
      else c=n-1-(s-1)/2;
      i=0;
    }
    i++;
  }
  printf("%d",s);
}
