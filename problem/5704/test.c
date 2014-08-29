main()
{
  char a[201];
  for(;gets(a),a[0]!='*';)
  {
    char ck[128]={0};
    int i;
    for(i=0;a[i];i++)ck[a[i]]++;
    for(i='a';i<='z';i++)if(ck[i]==0)break;
    puts(i>'z'?"Y":"N");
  }
}

