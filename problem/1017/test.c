int n,one,k;
int prime[2000]={0};
int check[1001];
int arr[51]={0};
int suc[51]={0};
int sucI;
typedef struct SP{int a,b;}SP;
SP sp[51];

f(i,s)
{
  int j;
  if(s==n)
  {
    return 1;
  }
  for(j=i+1;j<k;j++)
  {
    if(check[sp[j].a]||check[sp[j].b])continue;
    check[sp[j].a]=check[sp[j].b]=1;
    if(f(j,s+2))return 1;
    check[sp[j].a]=check[sp[j].b]=0;
  }
  return 0;
}


cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
main()
{

  int era[2001]={0};

  int i,j;
  for(i=2;i<=2000;i++)
  {
    if(era[i]==0)
    {
      prime[i]=1;
      for(j=i*i;j<=2000;j+=i)era[j]=1;
    }
  }
  scanf("%d",&n);
  for(i=0;i<n;scanf("%d",arr+i++));
  for(k=i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(prime[arr[i]+arr[j]])
      {
        sp[k].a=arr[i];sp[k].b=arr[j];
        k++;
        printf("%d %d\n",arr[i],arr[j]);
      }
    }
  }
  for(i=0;i<k;i++)
  {
    check[sp[i].a]++;check[sp[i].b]++;
  }
  for(i=0;i<n;i++)
  {
    printf("%8d ",arr[i]);
  }puts("");
  for(i=0;i<n;i++)
  {
    printf("%8d ",check[arr[i]]);
  }puts("");
  if(!sucI)puts("-1");
  else
  {
    qsort(suc,sucI,4,cmp);
    for(i=0;i<sucI;i++)printf("%d ",suc[i]);
  }
}
