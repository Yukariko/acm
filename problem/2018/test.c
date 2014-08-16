main()
{
  int n;
  scanf("%d",&n);
  int i,j,k,s,m,p,q;
  for(i=1;i*(i+1)/2<n;i++);
  s=0;
  for(j=1;j<=i;j++)
  {
    for(k=j;k>=0;k--)
    {
      p=n/j-k;
      q=p+j;
      m=q*(q+1)/2-p*(p+1)/2;
      if(m==n){s++;break;}
    }
  }
  printf("%d",s);
}
