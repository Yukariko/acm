main()
{
  char a[201];
  int i,res=0;
  gets(a);
  for(i=0;a[i];i++)
  {
    if(isupper(a[i]) && (i + res) % 4)
    {
      res += 4 - (i + res) % 4;
    }
  }
  printf("%d",res);
}
