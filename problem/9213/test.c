#define M 2000001
int comp[M]={0}; 
main()
{  
  long long i,j,k;
  for(i=1;i<M;i++)
  {
    for(j=i*2;j<M;j+=i)
    {
      comp[j]+=i;
    }
    comp[i]=abs(i-comp[i]);
  }
  
  int start,stop,badness;
  int t;
  for(t=1;scanf("%d%d%d",&start,&stop,&badness),start;t++)
  {
    int s=0;
    for(;start<=stop;start++)
    {
      if(comp[start]<=badness)s++;
    }
    printf("Test %d: %d\n",t,s);
  }
}
