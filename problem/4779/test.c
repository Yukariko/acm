char a[531442];i;
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
  for(;~scanf("%d",&n);){
    k=1;
    for(i=0;i<n;i++)k*=3;
    for(i=0;i<k;i++)a[i]='-';
    a[k]=0;
    f(0,k);
    puts(a);
  }
}
