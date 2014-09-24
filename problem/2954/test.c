main()
{
  char a[101];
  char res[101];
  gets(a);
  int i,j;
  for(i=j=0;a[i];i++)
  {
    res[j++]=a[i];
    if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
    {
      i+=2;
    }
  }
  res[j]=0;
  puts(res);
}
