main()
{
  int N;
  int a[50001],pos[50001];
  memset(pos,-1,sizeof(pos));
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
    pos[a[i]] = i;
  }
  for(int i=0;i<N;i++)
  {
    int cat = pos[a[i]-1];
    if(cat != -1 && cat > i)
    {
      int t=a[i];
      a[i]=a[cat];
      a[cat]=t;
    }
  }
  for(int i=0;i<N;i++)printf("%d ",a[i]);
}
