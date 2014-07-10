m;p;q;i;k;a[1001];x,y;t;
f2(n,s,t)
{
  for(;n<=k;n<<=1)s++;
  n-=k+1;
  for(;n;n>>=1)t+=n%2?1:0;
  printf("%d %d\n",s,t);
  return t;
}
f(n,s)
{
  //printf("%d\n",n);
  a[i++]=n;m=10001;
  if(n<k)
  {
    for(p=0;p<i;p++){
      t=abs(k-n-a[p]);
      if(m>t){m=t;x=a[p];}
    }
  }
  else if (n>k)
  {
    for(p=0;p<i;p++)
    {
      t=abs(k-n+a[p]);
      if(m>t){m=t;x=-a[p];}
    }
  }
  if(n==k)
  {
    return s;
  }
  else
  {
    return f(n+x,s+1);
  }
}
main(){for(gets(&k);~scanf("%d",&k);i=0)f2(1,0,0),printf("%d\n",f(1,0));}
