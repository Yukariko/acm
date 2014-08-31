main()
{
  int n,s;
  scanf("%d",&n);
  if(n<8){puts("-1");return;}
  else if(n%2==0)
  {
    printf("2 2 ");
    n-=4;
  }
  else
  {
    printf("2 3 ");
    n-=5;
  }
  long long i,j;
  char che[1000001]={};
  for(i=2;i<=n;i++)
  {
    if(che[i]==0)
    {
      for(j=i*i;j<=n;j+=i)che[j]=1;
    }
  }
  for(s=2;s<=n;s++)
  {
    if(che[s]==0&&che[n-s]==0)
    {
  	  printf("%d %d",s,n-s);
      return 0;
    }
  }  
}
