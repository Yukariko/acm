int num[101];
int t,n,i,j,s;
gcd(a,b){return b?gcd(b,a%b):a;}
main()
{
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    for(i=0;i<n;scanf("%d",num+i++));
    for(s=i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
      {
        s+=gcd(num[i],num[j]);
      }
    }
    printf("%d\n",s);
  }
}
