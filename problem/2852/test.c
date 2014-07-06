m;s;N;time_cur;time_x;time_y;point_x;point_y;
main(team)
{
  for(scanf("%d",&N);N--;)
  {
    scanf("%d %d:%d",&team,&m,&s);
    if(point_x>point_y)time_x+=m*60+s-time_cur;
    else if (point_x<point_y)time_y+=m*60+s-time_cur;
    time_cur = m*60+s;
    team==1?point_x++:point_y++;
  }
  if(point_x>point_y)time_x+=48*60-time_cur;
  else if (point_x<point_y)time_y+=48*60-time_cur;
  printf("%02d:%02d\n%02d:%02d",time_x/60,time_x%60,time_y/60,time_y%60);
}
