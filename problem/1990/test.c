int prime[1350];
isPrime(p)
{
  int i;
  for(i=0;prime[i]*prime[i]<=p;i++)
  {
    if(p%prime[i]==0)return 0;
  }
  return 1;
}
char a[10];
int palin[790];
int k;
f(i,n)
{
  int p,q;
  if(i>n/2){q=atoi(a);if(q<=100000001&&isPrime(q)){palin[k++]=q;}return;}
  if(i){a[i]='0';a[n-i]='0';f(i+1,n);}
  for(p=1;p<=9;p++)
  {
    a[i]=p+'0';
    a[n-i]=p+'0';
    f(i+1,n);
  }
}
main()
{
  int i,j,p=0;
  char che[10001]={};
  for(i=2;i<=10000;i++)
  {
    if(!che[i])
    {
      prime[p++]=i;
      for(j=i*i;j<=10000;j+=i)che[j]=1;
    }
  }
  for(i=0;i<=7;i++)
  {
    f(0,i);
  }
  palin[k]=100000001;
  int a,b;
  scanf("%d%d",&a,&b);
  for(i=0;palin[i]<a;i++);
  for(;palin[i]<=b;i++)
  {
    printf("%d\n",palin[i]);
  }
  puts("-1");
}
