main()
{
  int p,q;
  scanf("%d%d",&p,&q);
  char a[11]={0};
  int i,j,k=10,t=2,c=0,max=0;
  a[k-1]='0';
  for(i=0;atoi(a+k)<=q;i++)
  {
    if(atoi(a+k)>max&&atoi(a+k)>=p){max=atoi(a+k);c++;}
    if(i%t==0){k--;t*=2;}
    for(j=9;j>=k;j--)
    {
      if(a[j]=='4'){a[j]='7';break;}
      else a[j]='4';
    }
  }
  printf("%d",c);
}
