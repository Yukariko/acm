int cross[4],map[10000];
int i,j,m,s,p;
makeCross(a,b,c,d)
{
  return a*1000+b*100+c*10+d;
}
selectCross(a,b,c,d)
{
  cross[0]=makeCross(a,b,c,d);
  cross[1]=makeCross(b,c,d,a);
  cross[2]=makeCross(c,d,a,b);
  cross[3]=makeCross(d,a,b,c);
  for(m=i=0;i<4;i++)m=cross[m]>cross[i]?i:m;
  return cross[m];
}
main(a,b,c,d)
{
  scanf("%d%d%d%d",&a,&b,&c,&d);
  p=selectCross(a,b,c,d);
  for(j=1111;j<10000;j++)
  {
    a=j/1000;b=j/100%10;c=j/10%10;d=j%10;
    if(!a||!b||!c||!d)continue;
    map[selectCross(a,b,c,d)]++;
  }
  for(i=1111;i<p;i++)map[i]&&s++;
  printf("%d",s+1);
}
