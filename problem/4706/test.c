main()
{
  double ta,tb; 
  for(;~scanf("%lf%lf",&ta,&tb),ta;)
  {
    printf("%.3lf\n",sqrt(ta*ta-tb*tb)/ta);
  }
}
