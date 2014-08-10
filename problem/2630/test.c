int arr[129][129];
int n;
int count;
int bool;
split(p,q,r)
{
  int i,j,off=0;
  for(i=0;i<r;i++)
  {
    for(j=0;j<r;j++)
    {
      if(arr[p+i][q+j]!=bool)
      {
        off=1;
        break;
      }
    }
    if(off)break;
  }
  if(!off){count++;return;}
  if(r==1){return;}
  split(p,q,r/2);
  split(p+r/2,q,r/2);
  split(p,q+r/2,r/2);
  split(p+r/2,q+r/2,r/2);
}
main()
{
  int i,j,c1,c2;
  scanf("%d",&n);
  for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&arr[i][j]);
  split(0,0,n);
  c1=count;count=0;
  bool=!bool;
  split(0,0,n);
  printf("%d\n%d",c1,count);
}
