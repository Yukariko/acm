char a[401];s[6];
i;j;k;
main(m,n)
{
  for(scanf("%d%d\n",&m,&n);i<m;i++)
  {
    int b[101]={0};
    gets(a);
    for(j=0;j<4;j++)
    {
      gets(a);
      for(k=0;k<n;k++)a[5*k+1]=='*'?b[k]++:0;
    }
    for(k=0;k<n;k++)s[b[k]]++;
  }
  gets(a);
  for(k=0;k<5;k++)printf("%d ",s[k]); 
}
