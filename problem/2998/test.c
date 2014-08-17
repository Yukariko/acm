main()
{
  char a[101];
  int i;
  i=strlen(gets(a))%3;
  if(i==1)
  {
    printf("%d",a[0]-'0');
  }
  if(i==2)
  {
    printf("%d",(a[0]-'0')*2+a[1]-'0');
  }
  for(;a[i];i+=3)printf("%d",(a[i]-'0')*4+(a[i+1]-'0')*2+a[i+2]-'0');
  
}
