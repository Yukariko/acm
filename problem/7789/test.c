isPrime(n)
{
  int i;
  if(n==1)return 0;
  for(i=2;i*i<=n;i++)if(n%i==0)return 0;
  return 1;
}
main()
{
  char a[8],c;
  scanf("%s %c",a+1,a);
  if(isPrime(atoi(a+1))==0)return puts("No"),0;
  puts(isPrime(atoi(a))?"Yes":"No");
}
