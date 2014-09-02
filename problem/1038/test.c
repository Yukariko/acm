main()
{
  int n;
  scanf("%d",&n);
  int s=0,t;
  long long i,j,k;
  for(i=1;s<n;i++)
  {
    if(i<10)s++;
    else
    {
      t=1;
      for(j=i;;j/=10)
      {
        if(j<10){k=1;break;}
        if(j%10>=j/10%10){k=0;break;}
        t*=10;
      }
      if(k==0)
      {
        //i+=1;
      }  
      else s++;
    }
  }
  printf("%lld",i-1);
}
