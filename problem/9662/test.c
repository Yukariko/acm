#define LIMIT 1100
#define HLIMIT 550
main()
{
  int m,k;
  int a[25],b[LIMIT+1]={};
  int i,j;
  scanf("%d%d",&m,&k);
  for(i=0;i<k;i++)scanf("%d",a+i);
  b[0]=2;
  for(i=1;i<=LIMIT;i++)
  {
    for(j=0;j<k&&a[j]<=i;j++)
    {
       if(b[i-a[j]]==2)
       {
         b[i]=1;
         break;
       }
    }
    if(b[i]==0)b[i]=2;
  }

  for(i=1;i<=HLIMIT;i++)
  {
    for(j=i;j+i<=LIMIT;j++)
    {
      if(b[j]!=b[j+i])break;
    }
    if(j+i>LIMIT)break;
  }
    
  int count=0,res=0;
  if(m<=i)
  {
    for(j=1;j<=m;j++)res+=b[j]==2;
  }
  else 
  {
    for(j=1;j<i;j++)res+=b[j]==2;
    m-=i-1;
	for(j=0;j<i;j++)count+=b[j+i]==2;
    res+=m/i*count;
    for(j=0;j<m%i;j++)res+=b[j+i]==2;
  }
  printf("%d",res);
}
