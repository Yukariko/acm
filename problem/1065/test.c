int n,p,i,j,s;
main()
{
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    p=(i/10)%10-i%10;
    for(j=10;j<=i;j*=10)
    {
      if((i/j)%10-(i*10/j)%10!=p){s--;break;}
    }
    s++;
  }
  printf("%d",s);
}
