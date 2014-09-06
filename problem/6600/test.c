double area(double a,double b){return sqrt(a*a+b*b);}
double absd(double a){return a>0?a:-a;}
main()
{
  double x1,y1,x2,y2,x3,y3;
  for(;~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);)
  {
    double r,s;
    r=area(x1-x2,y1-y2)*area(x2-x3,y2-y3)*area(x3-x1,y3-y1);
    s=0.5*((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3));
    s=absd(s);
    r=r/(4*s);
    printf("%.2lf\n",r*2*3.1415926535);
  }
}
