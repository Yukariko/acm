main()
{
  int a,b;
  for(;scanf("%d%d",&b,&a),b;)
  {
    int t,h,w,min=151*151*2;
    h=b;
    w=a;
    t=h*h+w*w;
    int i,j,k;
    for(i=150;i;i--)
    {
      for(j=i+1;j<=150;j++)
      {
        k=i*i+j*j;
        if(t<k&&(k<min||(k==min&&h>i)))
        {
          min=k;
          h=i;
          w=j;
        }
        if(k==t&&b<i&&h>i)
        {
          min=k;
          h=i;
          w=j;
        }
      }
    }
    printf("%d %d\n",h,w);
  }
}
