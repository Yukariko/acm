int n,f,c,s;
main(i)
{
  for(;scanf("%d",&n),n;s=0)
  {   
    for(i=f=c=1;i<=n;i*=10,c++)
    {
      f*=c;
      s+=(n/i%10)*f;
    }
    printf("%d\n",s);
  }
}
