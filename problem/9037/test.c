main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,i,s,next;
    int a[11],b[11]={};
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n;i++)a[i]+=a[i]%2;
    for(s=0;;s++)
    {
      for(i=1;i<n;i++)if(a[i-1]!=a[i])break;
      if(i==n)break;
      
      for(i=0;i<n;i++)
      {
        next=(i+1)%n;
        b[i]+=a[i]/2;
        b[next]+=a[i]/2;
      }
      for(i=0;i<n;i++){a[i]=b[i]+b[i]%2;b[i]=0;}
    }
    printf("%d\n",s);
  }
}
