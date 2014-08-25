cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n,m;
  scanf("%d",&n);
  int crain[51];
  int box[51]={0};
  int i,j,k;
  for(i=0;i<n;i++)
  {
    scanf("%d",crain+i);
  }
  qsort(crain,n,4,cmp);
  scanf("%d",&m);
  for(i=0;i<m;i++)
  {
    scanf("%d",&k);
    for(j=0;j<n;j++)
    {
      if(k<=crain[j])
      {
        box[j]++;
        break;
      }
    }
    if(j==n){puts("-1");return;}
  }
  for(k=1;;k++)
  {
    for(i=0;i<n;i++)
    {
      if(box[i])box[i]--;
      else
      {
        for(j=i-1;j>=0;j--)if(box[j])break;
        if(j>=0)box[j]--;
      }
    }
    for(i=0;i<n;i++)if(box[i])break;
    if(i==n)break;
  }
  printf("%d",k);
}
