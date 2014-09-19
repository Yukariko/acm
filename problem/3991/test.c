main()
{
  int h,w,c;
  scanf("%d%d%d",&h,&w,&c);
  int a[10];
  int i,j,k;
  for(i=1;i<=c;i++)scanf("%d",a+i);
  char map[11][11]={};
  k=1;
  for(i=0;i<w;i++)
  {
    for(j=h-1;j>=0;j--)
    {
      if(a[k])
      {
        map[j][i]=k+'0';
        a[k]--;
      }
      else
      {
        k++;
        if(k>c)break;
        j++;
      }
    }
    if(j>=0)break;
  }
  for(i=0;i<h;i++)
  {
    puts(map[i]);
  }
}
