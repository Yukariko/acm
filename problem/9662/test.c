int M,K;
int a[23];
int b[23];
main()
{
  scanf("%d%d",&M,&K);
  int i,s=0;
  for(i=0;i<K;scanf("%d",a+i++));
  for(i=0;i<K;i++)b[a[i]]=1;
  for(i=1;i<=M;i++)
  {
    int j;
    for(j=0;j<K;j++)
    {
      if(i>a[j])if(b[(i-a[j])%23])break;
    }
    
  }
}
