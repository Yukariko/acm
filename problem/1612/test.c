main()
{
  int n;
  long long i;
  int j;
  scanf("%d",&n);
  if(n%2==0||n%5==0){puts("-1");return;}
  for(j=i=1;i%n;j++)
  {
    i=(i*10)%n+1;
  }
  printf("%d\n",j);
}
