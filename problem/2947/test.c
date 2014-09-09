main()
{
  int a[5];
  scanf("%d%d%d%d%d",a,a+1,a+2,a+3,a+4);
  int i,j,k,t,b;
  for(i=0;i<4;i++)
  {
    b=0;
    for(j=1;j<5;j++)
    {
      if(a[j-1]>a[j])
      {
        t=a[j-1];a[j-1]=a[j];a[j]=t;
        b=1;
        for(k=0;k<5;k++)printf("%d ",a[k]);
        puts("");        
      }
    }
    if(b==0)break;
  }
}
