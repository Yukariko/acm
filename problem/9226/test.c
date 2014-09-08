main()
{
  char a[21];
  char b[31];
  for(;gets(a),a[0]!='#';)
  {
    int i;
    for(i=0;a[i];i++)
    {
      if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
      {break;}
    }
    strcpy(b,a+i);
    a[i]=0;
    strcat(b,a);
    strcat(b,"ay");
    puts(b);
  }
}
