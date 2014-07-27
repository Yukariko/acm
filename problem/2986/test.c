int N;
f(a)
{
  int i;
  for(i=2;i*i<=a;i++)
  {
   if(a%i==0)return a/i;
  }
  return 1;
}
main()
{
  scanf("%d",&N);
  printf("%d",N-f(N));
}
