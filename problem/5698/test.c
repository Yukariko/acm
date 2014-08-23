main()
{
  char a,t,c=0;
  int b;
  for(b=-1;;)
  {
    scanf("%c",&t);
    if(t=='*')return;
    if(b==-1)
    {
      c=toupper(t);
      b=1;
    }
    else if(b==1)
    {
      if(c!=toupper(t))b=0;
    }
    for(;scanf("%c",&a);)
    {
      if(a=='\n')
      {
        puts(b?"Y":"N");
        b=-1;
        break;
      }
      if(a==32)break;
    }
  }
}

