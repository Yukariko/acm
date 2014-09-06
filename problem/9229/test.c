main()
{
  char a[21];
  char b[21];
  int ck;
  for(;gets(a),a[0]!='#';)
  {
    ck=0;
    for(;gets(b),b[0]!='#';)
    {
      int i,s;
      if(strlen(a)!=strlen(b))ck=1;
      for(i=s=0;a[i];i++)
      {
        s+=a[i]!=b[i];
      }
      if(s!=1)ck=1;
      strcpy(a,b);
    }
    puts(ck?"Incorrect":"Correct");
  }
}
