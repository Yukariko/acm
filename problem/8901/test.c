main()
{
  int N,m,M,T,R;
  scanf("%d%d%d%d%d",&N,&m,&M,&T,&R);
  int s,now=m,t;
  if(m+T>M){puts("-1");return;}
  for(t=s=0;t<N;s++)
  {
    if(now+T<=M)
    {
      now+=T;
      t++;
    }
    else
    {
      now-=R;
      now=now<m?m:now;
    }
  }
  printf("%d",s);
}
