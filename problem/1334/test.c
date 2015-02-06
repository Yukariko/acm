main()
{
  char a[54]={},b[54];
  a[0]='0';
  int len = strlen(gets(a+1));
  
  
  strcpy(b+1,a+1);
  
  for(int i=len/2;i;i--)
  {
    b[len - i + 1] = a[i];
  }
    
  if(strcmp(a+1,b+1) != -1)
  {
    int stok = 1;
    for(int i=len/2+len%2;i>=0 && stok;i--)
    {
      a[i] += stok;
      if(a[i] - '0' == 10)
      {
        a[i] = '0';
      }
      else
      {
        stok = 0;
      }
    }
  }
  for(int i=len/2;i;i--)
  {
    a[len - i + 1] = a[i];
  }
  if(a[0] != '0') a[len] = a[0];
  puts(a[0]=='0'?a+1:a);
}
