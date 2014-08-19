main()
{
  int a,b,c,d,e;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
  int i;
  for(i=1;;i++)
  {
    int s=0;
    if(i%a==0)s++;
    if(i%b==0)s++;
    if(i%c==0)s++;
    if(i%d==0)s++;
    if(i%e==0)s++;
    if(s>=3)break;
  }
  printf("%d",i);
}

