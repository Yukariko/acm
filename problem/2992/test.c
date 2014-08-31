int min=10000000;
char k[7];
char a[7];
int len;
int n;
f(c)
{
  int i;
  char t;
  for(i=0;i<len;i++)
  {
    if(a[i])
    {
      t=a[i];a[i]=0;k[c]=t;f(c+1);a[i]=t;
    }
  }
  if(c==len)
  {
    i=atoi(k);
    if(n<i)min=min>i?i:min;
  }
}
main()
{

  len=strlen(gets(a));
  n=atoi(a);
  int m;
  int i,j;
  f(0);
  if(min==10000000)puts("0");
  else printf("%d",min);
}
