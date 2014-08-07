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
      int first=0,last=j-1;
      for(;first<=last;)
      {
        p=(first+last)/2;
        if(arr[p]>k)last=p-1;
        else if (arr[p]<k) first = p+1;
      }
      p=first;
      for(q=0;q<p;q++)
      {
        arr[q]=arr[q+1];
      }
      arr[p-1]=k;
    }
  }
  printf("%d",arr[0]);
}

