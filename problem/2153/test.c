isPrime(p)
{
  int i;
  for(i=2;i*i<=p;i++)
  {
    if(p%i==0)return 0;
  }
  return 1;
}
main()
{
  char a[21];
  gets(a);
  int i;
  int s=0;
  for(i=0;a[i];i++)
  {
    if(a[i]>='a')s+=a[i]-'a'+1;
    else s+=a[i]-'A'+27;
  }
  puts(isPrime(s)?"It is a prime word.":"It is not a prime word.");
}
