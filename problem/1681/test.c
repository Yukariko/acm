main()
{
  int n,l,i,j,k,t;
  scanf("%d%d",&n,&l);
  k=0;
  for(i=1;k<n;)
  {
    for(t=1,j=i;j&&j%10!=l;j/=10,t*=10);
    if(!j){k++;i++;}
    else
    {
      i+=t;
    }
  }
  printf("%d",i-1);
}
