main()
{
  char map[10001]={0};
  int self[10001];
  int i,j,k=0;
  for(i=1;i<=10000;i++)
  {
    if(map[i]==0)
    {
      self[k++]=i;
      for(j=i;j<=10000;)
      {
        int t,s=0;
        for(t=j;t;t/=10)s+=t%10;
        j+=s;
        if(map[j])break;
        if(j<=10000)map[j]=1;
      }
    }
  }
  for(i=0;i<k;i++)printf("%d\n",self[i]);
}
