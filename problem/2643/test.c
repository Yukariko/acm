typedef struct paper{int w,h;}paper;
cmp(paper *a,paper *b){return a->w>b->w?-1:a->w<b->w?1:a->h>b->h?-1:a->h<b->h?1:0;}
binary_search(int *arr,int size,int num)
{
   int start=0,end=size-1,mid;
   while(start<=end)
   {
     mid=(end+start)/2;
     if(num>=arr[mid])start=mid+1;
     else if(num<arr[mid])end=mid-1;
   }
   return start;
}
LIS(paper *arr,int size)
{
  int *b=(int *)malloc(size*4);
  int i,j,k=0;
  for(i=size-1;i>=0;i--)
  {
    j=binary_search(b,k,arr[i].h);
    if(j==k)
    {
      b[k++]=arr[i].h;
    }
    else
    {
      b[j]=arr[i].h;
    }
  }
  free(b);
  return k;
}
main()
{
  int n;
  paper p[101];
  int i,j,t;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&p[i].w,&p[i].h);
    if(p[i].w<p[i].h){t=p[i].w;p[i].w=p[i].h;p[i].h=t;}
  }
  qsort(p,n,sizeof(paper),cmp);
  printf("%d",LIS(p,n));
}
