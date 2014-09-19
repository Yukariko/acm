int a[10001][2];
int level[10001][2];
int count;
f(i,l)
{
  if(i==-1)return;
  f(a[i][0],l+1);
  count++;
  if(!level[l][0])level[l][0]=count;
  else level[l][1]=count;
  f(a[i][1],l+1);
}
main()
{
  int n;
  scanf("%d",&n);
  int i;
  int parent[10001]={};
  for(i=0;i<n;i++)
  {
    int node,left,right;
    scanf("%d%d%d",&node,&left,&right);
    a[node][0]=left;
    a[node][1]=right;
    parent[left]=node;
    parent[right]=node;
  }
  for(i=1;parent[i];i++);
  f(i,1);
  int max=0,sel=1;
  for(i=1;i<10001;i++)
  {
    if(max<level[i][1]-level[i][0])
    {
      max=level[i][1]-level[i][0];
      sel=i;
    }
  }
  printf("%d %d",sel,max+1);
}
