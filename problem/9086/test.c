main()
{
  char a[1001];
  for(gets(a);gets(a);printf("%c%c\n",a[0],a[strlen(a)-1]));
}
