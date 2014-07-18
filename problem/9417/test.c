int num[101];
int t,n,i,j,s,m;
char tok;
gcd(a,b){return b?gcd(b,a%b):a;}
main()
{
  for(scanf("%d",&t);t--;)
  {
    for(i=0;scanf("%d%c",num+i++,&tok),tok!=10;);
    n=i;
    for(s=i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
      {
        m=gcd(num[i],num[j]);
        s=s<m?m:s;
      }
    }
    printf("%d\n",s);
  }
}
