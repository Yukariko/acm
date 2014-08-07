int arr[1501];
int n,nn;
int i,j,k;
cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}

main()
{
  int p,q,t;
  scanf("%d",&n);
  nn=n*n;
  for(j=i=0;i<nn;i++)
  {
    scanf("%d",&k);
    if(j<n)
    {
      arr[j++]=k;
      if (j==n) qsort(arr,j,4,cmp);
    }
    else if(arr[0]<k)
    {
      for(p=1;p<j;p++)if(k<arr[p])break;
      for(q=0;q<p;q++)
      {
        arr[q]=arr[q+1];
      }
      arr[p-1]=k;
    }
  }
  printf("%d ",arr[0]);
}

