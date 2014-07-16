double a[2],b[2],c[2];
double x,y;
double m[3],area,center[2];
int sign[3],t[3],s;
cmp(double m,double x0,double y0,double x1,double y1)
{
  double t = m*(x1-x0)+y0;
  return y1>t?-1:y1==t?0:1;
}

main(n)
{
  scanf("%lf%lf%lf%lf%lf%lf%d",a,a+1,b,b+1,c,c+1,&n);
  center[0]=(a[0]+b[0]+c[0])/3.0;
  center[1]=(a[1]+b[1]+c[1])/3.0;
  m[0]=(b[1]-a[1])/(b[0]-a[0]);
  m[1]=(c[1]-b[1])/(c[0]-b[0]);
  m[2]=(a[1]-c[1])/(a[0]-c[0]);
  sign[0]=cmp(m[0],b[0],b[1],center[0],center[1]);
  sign[1]=cmp(m[1],c[0],c[1],center[0],center[1]);
  sign[2]=cmp(m[2],a[0],a[1],center[0],center[1]);
  for(;~scanf("%lf%lf",&x,&y);)
  {
    t[0]=cmp(m[0],b[0],b[1],x,y);
    t[1]=cmp(m[1],c[0],c[1],x,y);
    t[2]=cmp(m[2],a[0],a[1],x,y);
    if((!t[0]||sign[0]==t[0])&&(!t[1]||sign[1]==t[1])&&(!t[2]||sign[2]==t[2]))s++;
  }
  area=(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))/2.0;
  printf("%.1lf\n%d",area>0?area:-area,s);
}
