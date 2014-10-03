#define MAX(a,b) (a>b?a:b)
binary_search(int *arr,int s,int e,int k)
{
  int start=s,mid,end=e-1;
  while(start<=end)
  {
    mid=(start+end)/2;
    if(arr[mid]<k)start=mid+1;
    else if(arr[mid]>k)end=mid-1;
    else return mid;
  }
  return -1;
}
main()
{
  int a[2][10001];
  int b[2][10001];
  int n,m,x,y;
  int i,j,p,q;
  for(;scanf("%d",&n),n;)
  {
    //Input
    for(i=0;i<n;i++)scanf("%d",&a[0][i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d",&a[1][i]);
    
    //Procedure
    int s;
    for(i=j=s=0;i<n;i++)
    {
      s+=a[0][i];
      p=binary_search(a[1],0,m,a[0][i]);
      if(p!=-1)
      {
        b[0][j++]=s;
        s=0;
      }
    }
    b[0][j++]=s;
    x=j;
    for(i=j=s=0;i<m;i++)
    {
      s+=a[1][i];
      p=binary_search(a[0],0,n,a[1][i]);
      if(p!=-1)
      {
        b[1][j++]=s;
        s=0;
      }
    }
    b[1][j++]=s;
    y=j;

    for(i=j=s=0;i<x;)
    {
      p=b[0][i];
      q=b[1][j];
      s+=MAX(p,q);
      i++;j++;
    }
    
    //Output
    printf("%d\n",s);
  }
}
