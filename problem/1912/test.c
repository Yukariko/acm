int n,s;
int arr[100001];
int sort[100001];
int window;
int max;
cmp(int *a,int *b){return *a>*b?-1:*a<*b?1:0;}
main()
{
  scanf("%d%d",&n,&s);
  int i,j;
  for(i=0;i<n;sort[i]=arr[i],i++)scanf("%d",arr+i);
  qsort(sort,n,4,cmp);
  for(window=i=0;i<n;i++)
  {
    window+=sort[i];
    if(window>=s)break;
  }
  for(++i;i<=n;i++)
  {
    window=0;
    for(j=0;j<i;j++)window+=arr[j];
    for(;j<n&&window<s;j++)
    {
      window=window-arr[j-i]+arr[j];
    }
    if(window>=s){printf("%d",i);return;}
  }
  puts("0");
}
