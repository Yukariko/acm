main()
{
  int N;
  for(;scanf("%d ",&N),N;)
  {
    int ck[1001]={};
    int pos,i,res;
    char a[1001];
    gets(a);
    
    for(pos=0;a[pos];pos++)
    {
      int p,q;
      for(i=pos;a[i] != ',' && a[i]; i++)if(a[i] == '-')break;
      if(a[i] != '-') ck[atoi(a+pos)]=1;
      else
      {
        sscanf(a+pos,"%d-%d",&p,&q);
        for(;p<=q && p <= N;p++)if(p>=1)ck[p]=1;
      }
      for(;a[pos] != ',' && a[pos];pos++);
    //  if(a[pos]==0)break;
    }
  
    res = 0;
    for(i=1;i<=N;i++)res += ck[i];
    printf("%d\n",res);
  }
} 
