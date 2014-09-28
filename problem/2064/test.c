getBit(n,p)
{
  return n&(1<<p)?1:0;
}
main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  int ip[1001][4];
  for(i=0;i<n;i++)
  {
    scanf("%d.%d.%d.%d",&ip[i][0],&ip[i][1],&ip[i][2],&ip[i][3]);
  }
  int a,b,c,d;  
  int na,nb,nc,nd;
  a=b=c=d=na=nb=nc=nd=0;
  for(j=0;j<32;j++)
  {
    for(i=1;i<n;i++)
    {
      if(getBit(ip[i][j/8],7-(j%8))!=getBit(ip[i-1][j/8],7-(j%8)))break;
    }
    if(i==n)
    {
      if(j/8==0){a=(a<<1)+getBit(ip[0][j/8],7-(j%8));na=(na<<1)+1;}
      if(j/8==1){b=(b<<1)+getBit(ip[0][j/8],7-(j%8));nb=(nb<<1)+1;}
      if(j/8==2){c=(c<<1)+getBit(ip[0][j/8],7-(j%8));nc=(nc<<1)+1;}
      if(j/8==3){d=(d<<1)+getBit(ip[0][j/8],7-(j%8));nd=(nd<<1)+1;}
    }
    else
    {
      if(j/8==0){a=a<<(8-j%8);na=(na<<(8-j%8));}
      if(j/8==1){b=b<<(8-j%8);nb=(nb<<(8-j%8));}
      if(j/8==2){c=c<<(8-j%8);nc=(nc<<(8-j%8));}
      if(j/8==3){d=d<<(8-j%8);nd=(nd<<(8-j%8));}
      break;
    }
  }
  printf("%d.%d.%d.%d\n%d.%d.%d.%d",a,b,c,d,na,nb,nc,nd);
}
