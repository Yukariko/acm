char a[2001];
isPalin(p,q)
{
  int len=q-p;
  int i,j;
  if(len%2==0)
  {
    i=p+len/2-1;
    j=p+len/2;
    for(;i>=p&&j<q;i--,j++)if(a[i]!=a[j])return 0;
  }
  else
  {
    i=p+len/2;
    j=i;
    for(;i>=p&&j<q;i--,j++)if(a[i]!=a[j])return 0;    
  }
  return 1;
}
main()
{
  int len=strlen(gets(a));
  int i,j,k,s=0;
  for(j=i=0;;)
  {
    for(i=len;i>=j;i--)
    {
      if(isPalin(j,i))break;
    }
//    printf("%d %d\n",j,i);
    j=i;
    s++;
    if(i==len)break;
  }
  printf("%d",s);
}
