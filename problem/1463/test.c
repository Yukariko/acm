//f(a,c,m){a>1?m=a%3+f(a/3)+1:0,c=a>1?a%2+f(a/2)+1:0:0;return c<m?c:m;}main(n){scanf("%d",&n);printf("%d",f(n));}
c=987654321;
f(n,s)
{
  if(n!=1)
  {
    n%3?f(n-1,s+1):f(n/3,s+1);
    n%2?0:f(n/2,s+1);
  }
  else
  {
    c=c>s?s:c;
  }
}
main(n){scanf("%d",&n);f(n,0);printf("%d",c);}
