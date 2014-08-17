gcd(a,b){return b?gcd(b,a%b):a;}
main()
{
  int t;
  int m,n,x,y;
  int i,j,k,temp,p;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d%d%d",&m,&n,&x,&y);
    p=m*n/gcd(m,n);
    if(x>n)
    {
      temp=m;m=n;n=temp;
      temp=x;x=y;y=temp;
    }
    for(i=j=k=x;k<=p&&j!=y;k+=m)j=(j+m-1)%n+1;
    printf("%d\n",k>p?-1:k);
  }
}
