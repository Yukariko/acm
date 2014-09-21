typedef struct Queen{int x,y;}Queen;
main()
{
  int t;
  Queen q[51];
  for(t=5;t--;)
  {
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
      scanf("%d%d",&q[i].x,&q[i].y);
    }
    int turn,win=-1;
    for(turn=0;;turn=!turn)
    {
      for(i=0;i<n;i++)
      {
        if(q[i].x==0||q[i].y==0||q[i].x==q[i].y)
        {
          win=turn;
          break;
        }
      }
      if(win!=-1)break;
      for(i=0;i<n;i++)
      {
        if(q[i].x>1)
        {
          if(q[i].x==2&&q[i].y==1)continue;
          if(q[i].y==1)q[i].x=2;
          else q[i].x=1;
          break;
        }
        if(q[i].y>1)
        {
          if(q[i].y==2&&q[i].x==1)continue;
          if(q[i].x==1)q[i].y=2;
          else q[i].y=1;
          break;
        }
      }
      if(i==n)
      {
        q[0].x=0;
      }
    }
    puts(win?"D":"S");
  }
}
