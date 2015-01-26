binary_search(int *arr,int size,int num)
{
   int start=0,end=size-1,mid;
   while(start<=end)
   {
     mid=(end+start)/2;
     if(num>arr[mid])start=mid+1;
     else if(num<arr[mid])end=mid-1;
     else return mid;
   }
   return start;
}
LIS(int N)
{
  int *b=(int *)malloc(N*4);
  int i,j,k=0;
  for(;N--;)
  {
    scanf("%d",&i);
    j=binary_search(b,k,i);
    if(j==k)
    {
      b[k++]=i;
    }
    else
    {
      b[j]=i;
    }
  }
  free(b);
  return k;
}

main()
{
	int N;
	for(;~scanf("%d",&N);)
	{
		printf("%d\n",LIS(N));
	}
}
