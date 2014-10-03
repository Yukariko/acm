#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
int a[300001][2];
main()
{
  int n,x;
  long long C=0;
  int root,node;
  int min,max,minCount,maxCount;
  scanf("%d",&n);
  scanf("%d",&root);
  min=max=root;
  minCount=maxCount=1;
  puts("0");
  for(;--n;)
  {
    scanf("%d",&x);
    if(x<min)
    {
      a[min][0]=x;
      min=x;
      C+=minCount++;
    }
    else if(x>max)
    {
      a[max][1]=x;
      max=x;
      C+=maxCount++;
    }
    else
    {
      for(node=root;;)
      {
        C++;
        if(x<node)
        {
          if(a[node][0]==0){a[node][0]=x;break;}
          else node=a[node][0];
        }
        else
        {
          if(a[node][1]==0){a[node][1]=x;break;}
          else node=a[node][1];
        }
      }
    }
    printf("%lld\n",C);
  }
}
