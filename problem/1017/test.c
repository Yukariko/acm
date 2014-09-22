cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
typedef struct pair{int x,y;}pair;
char map[51][51];
int a[51];
int visit[51];
pair p[2000];
isPrime(n){int i;for(i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
int n;
main()
{
  scanf("%d",&n);
  int i,j,k=0;
  for(i=0;i<n;scanf("%d",a+i++));
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(isPrime(a[i]+a[j]))
      {
        map[i][j]=map[j][i]=1;
      }
    }
  }
  
  int res[51];
  int s,t=0;
  for(k=1;k<n;k++)
  {
    if(map[0][k])
    {
      for(i=1;i<n;i++)
      {
        for(j=i+1;j<n;j++)
        {
          if(i==k||j==k)continue;
          if(map[i][j])
          {
            visit[i]++;
            visit[j]++;
          }
        }
      }
      for(s=i=0;i<n;i++){s+=visit[i]==0;visit[i]=0;}
      if(s==2)res[t++]=a[k];
    }
  }
  if(t==0)puts("-1");
  else
  {
    qsort(res,t,4,cmp);
    for(i=0;i<t;i++)printf("%d " ,res[i]);
  }
}
