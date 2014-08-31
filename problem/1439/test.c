main()
{
  char a[1000001];
  gets(a);
  int one=0,zero=0;
  char state=0;
  int i;
  for(i=0;a[i];i++)
  {
    if(state!=a[i])
    {
      state=a[i];
      if(state=='1')one++;
      else zero++;
    }
  }
  printf("%d",one>zero?zero:one);
}
