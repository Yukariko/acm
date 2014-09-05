main()
{
  int sq[182];
  char che[32769]={};
  int count[32769]={};
  int tcount[32769];
  int i,j,k=0;
  for(i=1;i*i<=32768;i++)sq[k++]=i*i;
  for(i=0;sq[i]<=32768;i++)
  {
    che[sq[i]]++;
    count[sq[i]]++;
  }
  for(j=1;j<4;j++)
  {
    memset(tcount,0,sizeof(tcount));
    for(k=0;k<181;k++)
    {
      for(i=1;i<32768;i++)
      {
        if(che[i]==j)
        {
          tcount[i+sq[k]]=1;
        }
      }
    }
    for(i=1;i<=32768;i++)
    {
      if(tcount[i])
      {
        count[i]+=tcount[i];
        che[i]=j+1;
      }
    }
  }
  int n;
  for(;scanf("%d",&n),n;)
  {
    printf("%d\n",count[n]);
  }
}
