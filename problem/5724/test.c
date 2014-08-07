int n;
int i,s;
main()
{
  for(;scanf("%d",&n),n;)
  {
    s=0;
    for(i=1;i<=n;i++)
    {
      s=i*i+s;
    }
    printf("%d\n",s);
  }
}
