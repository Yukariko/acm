char a[9];
int i,k,reverse;
main(n)
{
  for(gets(a);~scanf("%d",&n);reverse=0)
  {
    for(i=1;i<=n;i*=10)reverse=reverse*10+n/i%10;
    n+=reverse;
    k=sprintf(a,"%d",n);
    for(i=k/2-!(k%2),k=k/2;i>=0&&a[i]==a[k];i--)k++;
    puts(i>=0?"NO":"YES");
  }
}
