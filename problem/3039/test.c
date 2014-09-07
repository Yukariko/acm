typedef struct Study{long long a,b;}Study;
main()
{
  int n;
  Study study[200001];
  scanf("%d",&n);
  int i,j,k=0;
  int p,q;
  char c;
  for(;n--;)
  {
    scanf(" %c",&c);
    if(c=='D')
    {
      scanf("%d%d",&p,&q);
      study[k].a=p;study[k].b=q;
      k++;
    }
    else
    {
      scanf("%d",&p);
      p-=1;
      long long min=20000000001,depth=0;
      int pic;
      for(i=0;i<k;i++)
      {
        if(i!=p&&study[p].a<study[i].a&&study[p].b<=study[i].b)
        {
          if(min>study[i].b-study[p].b)
          {
            min=study[i].b-study[p].b;
            depth=study[i].a-study[p].a;
            pic=i;
          }
          else if(min==study[i].b-study[p].b)
          {
            if(depth>study[i].a-study[p].a)
            {
              depth=study[i].a-study[p].a;
              pic=i;
            }
          }
        }
      }
      if(min==2000000001)puts("NE");
      else printf("%d\n",pic+1);
    }
  }
}
