cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
int a[200001];
int b[200001];
main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=0;i<n;i++)scanf("%d",a+i);
  for(i=0;i<m;i++)scanf("%d",b+i);
  qsort(a,n,4,cmp);
  qsort(b,m,4,cmp);
  j=0;
  a[j++]=a[0];
  for(i=1;i<n;i++)
  {
    if(a[i-1]!=a[i])
    {
      a[j++]=a[i];
    }
  }
  n=j;
  j=0;
  b[j++]=b[0];
  for(i=1;i<m;i++)
  {
    if(b[i-1]!=b[i])
    {
      b[j++]=b[i];
    }
  }
  m=j;
  
  int s=0;
  for(i=0;i<n;i++)if(bsearch(&a[i],b,m,4,cmp)==0)s++;
  for(i=0;i<m;i++)if(bsearch(&b[i],a,n,4,cmp)==0)s++;
  printf("%d",s);
}
