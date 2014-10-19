int N,M,S;
char check[8193];
char visit[8193];
int seqVisit[8193];
int resVisit[8193];
int seqMove[8193];
int resMove[8193];
int max;
print()
{
  int i;
  printf("%d\n",max);
  for(i=0;i<max;i++)printf("%d(%d) ",resVisit[i],resMove[i]);
  puts("");
}
isOK(pos)
{
  return !(pos<=0||pos>N||visit[pos]);
}
f(pos,count)
{
  int i;
  if(max <= count)
  {
    S=1;
    max=count;
    for(i=0;i<count;i++)
    {
      resVisit[i]=seqVisit[i];
      resMove[i]=seqMove[i];
    }
  }
  if(max==N)
  {
    if(S)
    {
      print();
      system("pause");
      S=0;
    }
    //return;
  }
  for(i=1;i<N;i++)
  {
    if(check[i]==0)
    {
      check[i]=1;
      if(isOK(pos-i))
      {
        seqVisit[count]=pos-i;
        visit[pos-i]=1;
        seqMove[count]=-i;
        f(pos-i,count+1);
        visit[pos-i]=0;
      }
      if(isOK(pos+i))
      {
        seqVisit[count]=pos+i;
        seqMove[count]=i;
        visit[pos+i]=1;
        f(pos+i,count+1);
        visit[pos+i]=0;
      }
      check[i]=0;
    }
  }
}
main()
{
  int i;
  scanf("%d%d",&N,&M);
  visit[M]=1;
  seqVisit[0]=M;
  seqMove[0]=0;
  f(M,1);
}

