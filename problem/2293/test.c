n;k;j;i;a[101];b[10001];t;
f(i,j)
{
  if(i==k)b[0]++;
  if(i<k)for(j=0;j<n;j++)f(i+a[j],0);
}
main(){for(scanf("%d%d",&n,&k);~scanf("%d",&a[t++]););
  f(0,0);
  printf("%d",b[0]);
}

