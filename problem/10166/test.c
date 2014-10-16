main()
{
  char angle[4000021]={};
  int d1,d2;
  int i,sel,res=0;
  scanf("%d%d",&d1,&d2);
  for(;d1<=d2;d1++)
  {
    for(i=0;i<d1;i++)
    {
      sel=4000020LL*i/d1;
      if(angle[sel]==0)
      {
      	res++;
      	angle[sel]=1;
      }
    }
  }
  printf("%d",res);
}
