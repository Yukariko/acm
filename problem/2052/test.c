main()
{
  int N;
  char a[251]={};
  scanf("%d",&N);
  a[0]=1;
  for(int i=1;i<=N;i++)
  {
    int m=0;
    for(int j=0;j<=i;j++)
    {
      if(m+a[j] & 1)
      {
        a[j] = (m+a[j]) / 2;
        m=10;
      }
      else 
      {
        a[j] = (m+a[j]) / 2;
        m=0;
      }
    }
  }
  printf("0.");
  for(int i=1;i<=N;i++)printf("%d",a[i]);
}
