char a[531442];i;j;l;
f(p,q)
{
  int x,z;
  if(q-p>2)
  {
    x=p+(q-p)/3;
    z=p+(q-p)*2/3;
    for(;x<z;x++)a[x]=' ';
    f(p,p+(q-p)/3);
    f(z,q);
  }
}
main(n,k){
  for(scanf("%d",&n);j<n;j++){
    l=1;for(i=0;i<j;i++)l*=3;
    for(k=0;k<n/l;k++)
    {
      for(i=0;i<l;i++)a[i]='*';
      a[l]=0;
      f(0,l);
      printf("%s",a);
    }
    puts("");
  }
}
