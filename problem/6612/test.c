typedef struct ant{int pos;char move}ant;
main()
{
  int l,n;
  ant a[100001];
  for(;~scanf("%d%d",&l,&n);)
  {
    int i,j,k,max=0;
    for(i=0;i<n;i++)
    {
      scanf("%d %c",&a[i].pos,&a[i].move);
      j=a[i].move=='L'?a[i].pos:l-a[i].pos;
      max=max<j?j:max;
    }
    int p=-1,q=-1;
    for(i=0;i<n;i++)
    {
      j=a[i].move=='L'?a[i].pos:l-a[i].pos;
      if(max==j)
      {
        int m=0;
        if(p==-1)
        {
          for(j=0;j<n;j++)
          {
            k=a[j].move=='L'?a[j].pos:l-a[j].pos;
            if(k!=max&&a[i].move!=a[j].move)
            {
              if(a[i].move=='L'&&a[i].pos-a[j].pos>m)
              {
                m=a[i].pos-a[j].pos;
                p=a[j].pos;
              }
              else if(a[i].move=='R'&&a[j].pos-a[i].pos>m)
              {
                m=a[j].pos-a[i].pos;
                p=a[j].pos;
              }
            }
          }
        }
        else
        {
          for(j=0;j<n;j++)
          {
            k=a[j].move=='L'?a[j].pos:l-a[j].pos;
            if(k!=max&&a[i].move!=a[j].move)
            {
              if(a[i].move=='L'&&a[i].pos-a[j].pos>m)
              {
                m=a[i].pos-a[j].pos;
                q=a[j].pos;
              }
              else if(a[i].move=='R'&&a[j].pos-a[i].pos>m)
              {
                m=a[j].pos-a[i].pos;
                q=a[j].pos;
              }
            }
          }
          break;
        }
      }
    }
    printf("The last ant will fall down in %d seconds - started at ",max);
    if(q==-1)printf("%d.\n",p==-1?a[0].pos:p);
    else printf("%d and %d.\n",p<q?p:q,p<q?q:p);
  }
}
