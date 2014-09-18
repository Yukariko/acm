main()
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a==b+c)return printf("%d=%d+%d",a,b,c),0;
  if(a==b*c)return printf("%d=%d*%d",a,b,c),0;
  if(a==b-c)return printf("%d=%d-%d",a,b,c),0;
  if(a==b/c)return printf("%d=%d/%d",a,b,c),0;
  if(a+b==c)return printf("%d+%d=%d",a,b,c),0;
  if(a-b==c)return printf("%d-%d=%d",a,b,c),0;
  if(a*b==c)return printf("%d*%d=%d",a,b,c),0;
  if(a/b==c)return printf("%d/%d=%d",a,b,c),0;
  if(a==b&&b==c)return printf("%d=%d=%d",a,b,c),0;
}
