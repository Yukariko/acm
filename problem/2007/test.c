#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a<b?b:a)
cmp(long long *a,long long *b){return *a>*b?1:*a<*b?-1:0;}
long long arr[20001];
long long s[20001];
long long dp[20001][2];
int n,e,m,ck,size;
find(long long p)
{
  int i;
  for(i=0;i<size;i++)if(dp[i][0]==p)return i;
  return -1;
}
f(p)
{
  long long a,b,c,k;
  for(k=2;p+k<e;k++)
  {
    if((arr[p]-arr[p+1]+arr[p+k])%2)continue;
    b=(arr[p]-arr[p+1]+arr[p+k])/2;
    a=arr[p]-b;
    c=arr[p+1]-a;
    if(a+b==arr[p]&&a+c==arr[p+1])break;
  }
  if(p+k==e){puts("Impossible");exit(0);}
  ck=p+k;
  s[m++]=a;
  s[m++]=b;
  s[m++]=c;
}
main()
{ 
  scanf("%d",&n);
  int i,j,k;
  e=n*(n-1)/2;
  for(i=0;i<e;i++)scanf("%lld",arr+i);
  qsort(arr,e,8,cmp);
  if(n==1)return puts("1"),0;
  if(n==2)return printf("%lld %lld",MIN(arr[0]-1,1),MAX(arr[0]-1,1)),0;
  
  f(0);
  for(i=2;i<e;i++)
  {
    if(i==ck)continue;
    for(j=0;j<3;j++)
    {
      k=find(arr[i]-s[j]);
      if(k==-1)
      {
        dp[size][0]=arr[i]-s[j];
        dp[size++][1]=1;
      }
      else dp[k][1]++;
    }
  }
  for(i=0;i<size;i++)
  {
    if(dp[i][1]>=3)s[m++]=dp[i][0];
  }
  if(n!=m)return puts("Impossible"),0;
  qsort(s,m,8,cmp);
  for(i=0;i<m;i++)
  {
    printf("%lld ",s[i]);
  }
}
