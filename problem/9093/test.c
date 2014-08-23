main()
{
  int t;
  for(scanf("%d ",&t);t--;)
  {
    char a[1001];
    gets(a);
    int i,j;
    
    for(j=i=0;a[i];i++)
    {
      if(a[i]==' ')
      {
        int k;
        for(k=i-1;k>=j;k--)putchar(a[k]);
        putchar(' ');
        j=i+1;
      }
    }
    int k;
    for(k=i-1;k>=j;k--)putchar(a[k]);
    puts("");
  }  
}
