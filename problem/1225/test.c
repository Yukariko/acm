long long s,t;
main()
{
  char A[10001],B[10001];
  scanf("%s%s",A,B);
  int i,j;
  for(i=0;B[i];i++)t+=B[i]-'0';
  for(i=0;A[i];i++)
  {
    s+=(A[i]-'0')*t;
  }
  printf("%lld",s);
}
