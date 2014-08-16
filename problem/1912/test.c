main()
{
  int n,i,k,s,m=1<<31;
  scanf("%d",&n);
  for(s=i=0;i<n;i++)
  {
    scanf("%d",&k);
    if(s<0)s=k;
    else s+=k;
    m=m<s?s:m;
  }
  printf("%d",m);
}
