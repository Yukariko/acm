cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n;
  scanf("%d",&n);
  int a[10001];
  int i,j,k;
  for(i=0;i<n;i++)scanf("%d",a+i);
  qsort(a,n,4,cmp);
  int min=5,s;
  for(i=0;i<n;i++)
  {
    int ck[5]={};
    s=5;
    for(j=0;j<5&&i+j<n;j++)
    {
      k=a[i+j]-a[i];
      if(k>=0 && k<5 && ck[k] == 0)
      {
        ck[k]=1;
        s--;
      }
      else break;
    }
    min=min>s?s:min;
  }
  printf("%d",min);
}
