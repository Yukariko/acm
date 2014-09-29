typedef struct pair{int x,y;}PAIR;
cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
cmp2(PAIR *a,PAIR *b){return a->x>b->x?1:a->x<b->x?-1:0;}
int a[51];
int visit[51];
int jump[51];
PAIR pair[2000];
isPrime(n){int i;for(i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
int n,k,bool;
f(p,c)
{
  if(c==0){bool=1;return;}
  if(p>=n)return;
  int i;

  if(visit[p]||jump[p]==-1){f(p+1,c);return;}
  visit[p]=1;
  for(i=jump[p];pair[i].x==p;i++)
  {
    if(visit[pair[i].y]==0)
    {
      visit[pair[i].y]=1;
      f(p+1,c-2);
      visit[pair[i].y]=0;
    }
    if(bool){visit[p]=0;return;}
  }
  visit[p]=0;
}
main()
{
  scanf("%d",&n);
  int i,j;
  for(i=0;i<n;scanf("%d",a+i++));
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(isPrime(a[i]+a[j]))
      {
        pair[k].x=i;
        pair[k].y=j;
        k++;
      }
    }
  }
  qsort(pair,k,8,cmp2);
  int res[51];
  int s,t=0;
  visit[0]=1;
  for(i=0;i<n;i++)jump[i]=-1;
  jump[0]=0;
  for(i=1;i<k;i++)if(pair[i].x!=pair[i-1].x)jump[pair[i].x]=i;
  for(i=0;pair[i].x==0;i++)
  {
    visit[pair[i].y]=1;
    bool=0;
    f(1,n-2);
    if(bool)res[t++]=a[pair[i].y];
    visit[pair[i].y]=0; 
  }
  if(t==0)puts("-1");
  else
  {
    qsort(res,t,4,cmp);
    for(i=0;i<t;i++)printf("%d " ,res[i]);
  }
}
