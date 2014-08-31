main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  for(i=0,j=n;j;j/=10,i++);
  j=n-i*9;
  int s;
  for(i=j;i<=n;i++)
  {
    s=i;
    for(j=i;j;j/=10)s+=j%10;
    if(s==n)break;
  }
  if(s!=n)puts("0");
  else printf("%d",i);
}
