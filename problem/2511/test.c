main()
{
  int i;
  int a[10];
  int b[10];
  for(i=0;i<10;scanf("%d",a+i++));
  for(i=0;i<10;scanf("%d",b+i++));
  int sa,sb,w=-1;
  for(sa=sb=i=0;i<10;i++)
  {
    if(a[i]>b[i]){sa+=3;w=0;}
    else if(a[i]==b[i]){sa+=1;sb+=1;}
    else{sb+=3;w=1;}
  }
  printf("%d %d\n%c",sa,sb,sa>sb?'A':sa<sb?'B':w>=0?'A'+w:'D');
}
