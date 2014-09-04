main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int l;
    int nx,ny;
    int gx,gy;
    scanf("%d",&l);
    scanf("%d%d",&nx,&ny);
    scanf("%d%d",&gx,&gy);
    int s,t;
    if(gx<nx)
    {
      t=gx;gx=nx;nx=t;
      t=gy;gy=ny;ny=t;
    }
    for(s=0;nx!=gx||ny!=gy;s++)
    {
      if((gx-nx)%2==1)
      {
        gx-=1;
        if(gy>ny)
        {
          if(gy>1)gy-=2;
          else gy+=2;
        }
        else 
        {
          if(gy<l-2)gy+=2;
          else gy-=2;
        }
      }
      else if(gx>1)
      {
        gx-=2;
        if(gy>ny)
        {
          if(gy>0)gy-=1;
          else gy+=1;
        }
        else 
        {
          if(gy<l-1)gy+=1;
          else gy-=1;
        }
      }
      else
      {
        gx+=2;
        if(gy>ny)
        {
          if(gy>0)gy+=1;
          else gy-=1;
        }
        else 
        {
          if(gy<l-1)gy-=1;
          else gy+=1;
        }
      }
      printf("%d %d\n",gx,gy);
      system("pause");
    }
    printf("%d\n",s);
  }
}
