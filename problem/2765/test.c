main()
{
  double len,time;
  int turn;
  int i;
  for(i=1;~scanf("%lf%d%lf",&len,&turn,&time),turn;i++)
  {
    double distance;
    distance=len*turn/63360*3.141592;
    printf("Trip #%d: %.2lf %.2lf\n",i,distance,distance/time*3600);
  }
}
