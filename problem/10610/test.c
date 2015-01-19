int cmp(char *p,char *q)
{
  return *q-*p;
}
main()
{
  char a[100001];
  int len = strlen(gets(a));
  qsort(a, len, 1, cmp);
  int check=0;
  for(int i=0;a[i];i++)check+=a[i]-'0';
  puts(check % 3 == 0 && a[len-1] == '0' ?a:"-1");
}
