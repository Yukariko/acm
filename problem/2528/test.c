typedef struct ladder{int len,pos;}ladder;
main()
{
  int n,l;
  ladder a[3001];
  scanf("%d%d",&n,&l);
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&a[i].len,&a[i].pos);
  }
  int time=0,p;
  for(p=n-1;p;time++)
  {
    for(;p;)
    {
      if(a[p].pos==a[p-1].pos)
      {
        p--;
      }
      else
      {
        if(a[p].len+a[p-1].len>=l)p--;
        else break;
      }
    }
    for(i=0;i<n;i++)
    {
      a[i].len++;
    }
  }
  printf("%d",time?time-1:0);
}
