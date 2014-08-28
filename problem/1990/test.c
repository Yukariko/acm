#define M 100000000
int prime[1000001];
isPrime(p)
{
  long long i;
  for(i=2;i*i<=p;i++)
  {
    if(p%i==0)return 0;
  }
  return 1;
}
main()
{
  int time;
  long long i,j,k=0,l=0,t=0;
  long long p,q,r,s=9;
  for(time=i=1;i<=M;i*=10,time++)
  {
    if(i!=1)i++;
    prime[k]=i;
    q=i;
    t=l;
    for(j=0;j<9;j++)
    {
      p=i/10;
      prime[k++]=q;
      if(i>10000)
      {
        r=i/1000;
        if(time%2)
        {
          for(l=0;prime[l]<r;l++)prime[k++]=q+prime[l]*100;
      //    s=l;
        }
        else
        {
          r=i/100;
          for(l=9;prime[l]<r;l++)prime[k++]=q+prime[l]*100;
          
        }
      }
      for(l=t;prime[l]<p;l++)
      {
        prime[k++]=q+prime[l]*10;
      }
      q+=i;
    }
    t=l;
    if(i!=1)i--;
  }
  int a,b;
  scanf("%d%d",&a,&b);
  for(i=0;prime[i]<a;i++);
  for(;prime[i]<=b;i++)
  {
    printf("%d\n",prime[i]);
    //if(isPrime(prime[i]))printf("%d\n",prime[i]);
  }
  puts("-1");
}
