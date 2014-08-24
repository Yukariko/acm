main()
{
  int n,j;
  double i;
  for(;~scanf("%d",&n);)
  {
    for(j=i=1;i!=ceil(i/n)*n;i=i*10+1,j++);
    printf("%d\n",j);
  }
}
