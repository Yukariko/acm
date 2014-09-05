cmp(float *a,float *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int nx,ny;
  float w;
  for(;scanf("%d%d%f",&nx,&ny,&w),nx;)
  {
    int i;
    float x[nx];
    float y[ny];
    for(i=0;i<nx;scanf("%f",x+i++));
    for(i=0;i<ny;scanf("%f",y+i++));
    qsort(x,nx,sizeof(float),cmp);
    qsort(y,ny,sizeof(float),cmp);
    float state=0;
    for(i=0;i<nx;i++)
    {
      if(state<75&&state<x[i]-w/2)break;
      else state=x[i]+w/2;
    }
    if(state<75){puts("NO");continue;}
    state=0;
    for(i=0;i<ny;i++)
    {
      if(state<100&&state<y[i]-w/2)break;
      else state=y[i]+w/2;
    }
    if(state<100){puts("NO");continue;}
    puts("YES");
  }
}
