int range_top[100001],range_bottom[100001];
int N,H,range,max_top,max_bottom;
int i,j,k,s,m;
cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
main()
{
  for(scanf("%d%d",&N,&H);i<N;i++)
  {
    scanf("%d",&range);
    if(!k)
    {
      range_bottom[j]=range;
    }
    else
    {
      range_top[j++]=range;
    }
    k=!k;
  }
  qsort(range_top,N/2,4,cmp);
  qsort(range_bottom,N/2,4,cmp);
  printf("%d %d\n",range_top[0],range_top[6]);
  printf("%d %d",m,s);
}
