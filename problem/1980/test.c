main()
{
  int n,m,t;
  scanf("%d%d%d",&n,&m,&t);
  int i,j,k,tmin=10001,max=0;
  for(i=0;i*n<=t;i++)
  {
    j=(t-i*n)/m;
    k=t-i*n-j*m;
    if(tmin>k)
    {
      tmin=k;
      max=i+j;
    }
    else if(tmin==k)max=max<i+j?i+j:max;
  }
  printf("%d %d",max,tmin); 
}
