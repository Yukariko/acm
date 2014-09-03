#define MIN(a,b) (a>b?b:a)
main()
{
  int x,y;
  int ax[101],ay[101];
  int w,h;
  int n;
  scanf("%d%d",&w,&h);
  scanf("%d",&n);
  int i;
  for(i=0;i<=n;i++)
  {
    int p,q;
    scanf("%d%d",&p,&q);
    ax[i]=p;ay[i]=q;
  }
  int s=0,l=2*w+2*h;
  for(i=0;i<n;i++)
  {
    if(ax[n]==1)
    {
      if(ax[i]==2)
      {
        int t=ay[n]+h+ay[i];
        s+=MIN(t,l-t);
      }
      if(ax[i]==1)
      {
        s+=abs(ay[i]-ay[n]);
      }
      if(ax[i]==3)
      {
        s+=ay[n]+ay[i];
      }
      if(ax[i]==4)
      {
        s+=w-ay[n]+ay[i];
      }
    }
    if(ax[n]==2)
    {
      if(ax[i]==1)
      {
        int t=ay[n]+h+ay[i];
        s+=MIN(t,l-t);
      }
      if(ax[i]==2)
      {
        s+=abs(ay[i]-ay[n]);
      }
      if(ax[i]==3)
      {
        s+=ay[n]+h-ay[i];
      }
      if(ax[i]==4)
      {
        s+=w-ay[n]+h-ay[i];
      }
    }
    if(ax[n]==3)
    {
      if(ax[i]==4)
      {
        int t=ay[n]+w+ay[i];
        s+=MIN(t,l-t);
      }
      if(ax[i]==3)
      {
        s+=abs(ay[i]-ay[n]);
      }
      if(ax[i]==1)
      {
        s+=ay[n]+ay[i];
      }
      if(ax[i]==2)
      {
        s+=h-ay[n]+ay[i];
      }
    }
    if(ax[n]==4)
    {
      if(ax[i]==3)
      {
        int t=ay[n]+w+ay[i];
        s+=MIN(t,l-t);
      }
      if(ax[i]==4)
      {
        s+=abs(ay[i]-ay[n]);
      }
      if(ax[i]==1)
      {
        s+=ay[n]+w-ay[i];
      }
      if(ax[i]==2)
      {
        s+=h-ay[n]+w-ay[i];
      }
    }
  }
  printf("%d",s);
}
