int tree[1025];
int depth[11][1025];
f(p,l,d)
{
  depth[d][++depth[d][0]]=tree[p];
  if(l==0)return;
  f(p-l,l>>1,d+1);f(p+l,l>>1,d+1);
}
main()
{
  int k;
  scanf("%d",&k);
  int i,j,end=(1<<k)-1;
  for(i=0;i<end;i++)
  {
    scanf("%d",tree+i);
  }
  f(end/2,1<<(k-2),0);
  for(i=0;i<k;i++)
  {
    for(j=1;j<=depth[i][0];j++)
    {
      printf("%d ",depth[i][j]);
    }
    puts("");
  }
}
