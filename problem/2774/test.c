int t,n;
main()
{
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    int i,s;
    int check[10]={0};
    for(i=1;i<=n;i*=10)check[n/i%10]=1;
    for(s=i=0;i<10;i++)s+=check[i];
    printf("%d\n",s);
  }
}
