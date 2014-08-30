char a[3073][6145];
f(i,j)
{
  int p;
  a[i][j]=a[i][j+1]=a[i][j+3]=a[i][j+4]=' ';
  a[i][j+2]='*';
  a[i+1][j]=a[i+1][j+2]=a[i+1][j+4]=' ';
  a[i+1][j+1]=a[i+1][j+3]='*';
  for(p=0;p<5;p++)a[i+2][j+p]='*';
}
f2(i,j,w,h,p,q)
{
  int r,s;
  for(r=0;r<h;r++)
  {
    for(s=0;s<w;s++)
    {
      a[p+r][q+s]=a[i+r][j+s];
    }
  }
}
main()
{
  int n;
  scanf("%d",&n);
  int i,j,k=2,l=0;
  int p,q,w,h;
  int r,s;
  p=n-3;
  r=0;s=p;
  for(i=0;i<3;i++)for(j=0;j<p;j++)a[i][j]=' ';
  f(0,j);
  j+=5;
  for(i=0;i<3;i++)for(q=0;q<p;q++)a[i][j+q]=' ';
  w=5;h=3;
  for(i=3;i<n;)
  {
    p=n-i*2;
    for(k=0;k<h;k++)for(j=0;j<p;j++)a[i+k][j]=' ';
    f2(r,s,w,h,i,j);j+=w;
    for(k=0;k<h;k++)a[i+k][j]=' ';j+=1;
    f2(r,s,w,h,i,j);j+=w;
    for(k=0;k<h;k++)for(q=0;q<p;q++)a[i+k][j+q]=' ';
    s=p;
    i+=h;
    w=w*2+1;h*=2;
  }
  for(i=0;i<n;i++)puts(a[i]);
}
