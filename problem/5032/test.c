main()
{
  int e,f,c;
  scanf("%d%d%d",&e,&f,&c);
  e+=f;
  int s=0;
  for(;e>=c;)
  {
    s+=e/c;
    e=e%c+e/c;
  }
  printf("%d",s);
}
