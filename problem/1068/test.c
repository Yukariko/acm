int a[51][2];
int count,no;
f(i)
{
  if(i==no)return;
  if((a[i][0]==-2||a[i][0]==no)&&(a[i][1]==-2||a[i][1]==no)){count++;return;}
  if(a[i][0]!=-2)f(a[i][0]);
  if(a[i][1]!=-2)f(a[i][1]);
}
main()
{
  int n;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
  {
    a[i][0]=a[i][1]=-2;
  }
  int k,t;
  for(i=0;i<n;i++)
  {
    scanf("%d",&k);
    if(k==-1)t=i;
    else if(a[k][0]==-2)a[k][0]=i;
    else a[k][1]=i;
  }
  scanf("%d",&no);
  f(t);
  printf("%d",count);
}
