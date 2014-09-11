main()
{
  int a,b,c;
  int x,y;
  int p[101]={};
  scanf("%d%d%d",&a,&b,&c);
  int i;
  for(i=0;i<3;i++)
  {
    scanf("%d%d",&x,&y);
    for(;x<y;x++)p[x]++;
  }
  int s=0;
  for(i=0;i<=100;i++)
  {
    if(p[i]==1)s+=a;
    else if(p[i]==2)s+=b*2;
    else if(p[i]==3)s+=c*3;
  }
  printf("%d",s);
}
