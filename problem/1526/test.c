main()
{
  int n;
  scanf("%d",&n);
  char a[11]={0};
  char b[11]={0};
  int i,j,k=10,t=2;
  a[k-1]='0';
  for(i=0;atoi(a+k)<=n;i++)
  {
    strcpy(b,a+k);
    if(i%t==0){k--;t*=2;}
    for(j=9;j>=k;j--)
    {
      if(a[j]=='4'){a[j]='7';break;}
      else a[j]='4';
    }
  }
  printf("%s",b);
}
