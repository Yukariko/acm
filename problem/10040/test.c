main()
{
  int n,m;
  int a[1001];
  int vote[1001]={};
  scanf("%d%d",&n,&m);
  int i,j,k;
  for(i=0;i<n;i++)scanf("%d",a+i);
  for(i=0;i<m;i++)
  {
    scanf("%d",&k);
    for(j=0;j<n;j++)if(k>=a[j]){vote[j]++;break;}
  }
  int max=0;
  for(i=0;i<n;i++)max=vote[max]<vote[i]?i:max;
  printf("%d",max+1);
}
