main()
{
  int n;
  scanf("%d ",&n);
  char a[201];
  int len=strlen(gets(a));
  char crypto[201][201]={}; 
  int i,j,k=0;
  for(j=0;j<len/n;j++)
  {
    if(j%2==0)for(i=0;i<n;i++){crypto[i][j]=a[k++];}
    else for(i=n-1;i>=0;i--){crypto[i][j]=a[k++];}
  }
    for(i=0;i<n;i++)for(j=0;j<len/n;j++)printf("%c",crypto[i][j]);
    puts("");
}
