main()
{
  char a[2501];
  char b[51];
  char t;
  int alen=strlen(gets(a));
  int blen=strlen(gets(b));
  int i,s=0;
  for(i=0;i<alen;i++)
  {
    t=a[i+blen];
    a[i+blen]=0;
    if(strcmp(a+i,b)==0)
    {
      a[i+blen]=t;
      s++;
      i+=blen-1;
    }
    else
    {
      a[i+blen]=t;
    }
  }
  printf("%d",s);
}
