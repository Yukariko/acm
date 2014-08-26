main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int i,j;
  for(i=0;k;)
  {
    i+=n/k;
    k--;
    n=k;
    
  }
  printf("%d",i);
}
